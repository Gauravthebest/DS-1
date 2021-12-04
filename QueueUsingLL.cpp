//Program of Queue using Linked LIST
//Compiled through online compiler 

#include <iostream>
#include <stdlib.h>
using namespace std; 
struct node {
    int data;
    struct node *next;
} *front, *back;
 
void init() {        // Creating an empty queue
    front = back = NULL;
}
 
int Size() {       // Returns queue size
    struct node *temp = front;
    int count = 0;
    if(front == NULL && back == NULL)
        return 0;
    while(temp != back){
        count++;
        temp = temp->next;
    }
    if(temp == back)
        count++;
    return count;
}
 
int frontval() {     // Returns Frnt Element of the Queue
    return front->data;
}

int backval() {      // Returns the Rear Element of the Queue 
    return back->data;
}

void isempty() {       //Check's if Queue is empty or not
    if (front == NULL && back == NULL)
        cout<<"Empty Queue\n";
    else
        cout<<"Queue is not Empty\n";
}

void enqueue(int num) {     //Adding elements in Queue

    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    temp->next = NULL;
     
    if (back == NULL) {
        front = back = temp;
    } else {
        back->next = temp;
        back = temp;
    }
}
 
void dequeue() {     //Removes an element from front of the queue
    struct node *temp;
    if (front == NULL) {
        cout<<"\nQueue is Empty \n";
        return;
    } else {
        temp = front;
        front = front->next;
        if(front == NULL){
            back = NULL;
        }
        cout<<"Removed Element =  "<<temp->data<<endl;
        free(temp);            //free() function for  de-allocation of memory ,dynamically
    }
}
  
void print() {    // Print's Queue
    struct node *temp = front;
    if ((front == NULL) && (back == NULL)) {
        cout<<"Queue is Empty\n";
        return;
    }
    while (temp != NULL) {
        cout<<temp->data;
        temp = temp->next;
        if(temp != NULL)
            cout<<"-->";
    }
}
 //Driver code 
int main() {
    cout<<"\n \t \tTHIS IS A PROGRAM OF QUEUE USING LINKED LIST --BY GAURAV"<<endl;
    init();     // Initializing Queue 
    enqueue(100);       // Adding elements in Queue 
    enqueue(99);
    enqueue(88);
    enqueue(77);
    enqueue(66);
    print();      // Printing Queue 
    cout<<"\nSize of Queue = "<< Size()<<endl;    // Printing size of Queue 
    cout<<"Front Element in a queue = "<< frontval()<<endl;   // Printing front and rear element of Queue
    cout<<"Rear Element in queue =  "<< backval()<<endl;
    dequeue();         // Removing Element from Queue 
    dequeue();
    dequeue();
    dequeue();    
    dequeue();
    dequeue();
    return 0;
}