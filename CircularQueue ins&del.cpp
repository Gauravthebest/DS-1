//PROGRAM FOR INSERTION AND DELETIONS OF ELEMENT IN THE QUEUE 
#include<stdio.h>
#include<iostream>
#include<conio.h>

using namespace std;
#define SIZE 15

int QUEUE[SIZE];
int front = -1, rear = -1;

//TO INSERT ELEMENTS IN THE QUEUE THROUGH THE REAR END
void enqueue(int val)
{
    if (rear == (SIZE - 1))
    {
        cout << "The QUEUE is FULL!! Addition not possible.";
        exit(1);
    }

    if ( front == -1)
        front = rear = 0;
    else 
        rear++;
    
    QUEUE [rear] = val;
}

//TO DELETE ELEMENTS IN THE QUEUE FROM THE FRONT END
int dequeue()
{
    int del = 0;
    if (front == -1 && rear == -1)
    {
        cout << "The QUEUE is EMPTY!! Deletion not possible.";
        exit(1);
    }
    else if (front == 0 && rear == 0)
    {
        del = QUEUE[front];
        front = rear = -1;
    }
    else
    {
        del = QUEUE[front];
        ++front;
    }
    return del ;
}

//TO DISPLAY THE ELEMENTS IN THE QUEUE FROM FRONT TO REAR END
void display()
{
    if(front == -1 && rear == -1)                               //if the stack is EMPTY
    {
        cout << "The QUEUE is EMPTY!!!";
        return;
    }
    for (int i = front; i <= rear; i++)
    cout << QUEUE[i] << "\t";
}

int main()
{
    int ch, val;
    char c;
    do{
        cout << "\nQUEUE OPERATIONS MENU -\n";
        cout << "\n 1)Insert an element in the queue";
        cout << "\n 2)Delete an element from the queue";
    
        cout << "\n\nEnter your choice : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter the value of the element to be inserted in the queue : ";
            cin >> val;
            enqueue(val);
            cout << "\nUsing the enqueue function \nQUEUE IS :-";
            display();
            break;

        case 2:
            cout << "\nDeleting the element from the front..." << endl;
            cout << dequeue() << " is the deleted element ";
            break;
        
        default:
            cout << "\nEnter a valid choice";
            break;
        }
        cout << "\n\nWant to perform more actions? Press y/Y for YES else n/N : ";
        cin >> c;
        if ((c == 'n') || (c == 'N'))
        {
        cout << "\nQUEUE after performing ADDITIONS and DELETIONS :- \n";
        display();
        }
    } while ((c == 'y') || (c == 'Y')); 
}
