//WAP to implement stack using linked list & perform the push & pop operations on it.
//Complied through Online compiler

#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    int info;
    struct node *ptr;
}*top,*top1,*temp;
 
void push(int data);
void pop();
void display();

int count = 0;
 
int main()
{
    int no, ch;
     top = NULL;
    cout<<"Here, Some listed operations in this program, which are as follows: - \n 1 - Push\n 2 - Pop\n 3 - display\n 4 - Exit"<<endl;
    
    while (1)
    {
        cout<<"\n Enter your choice : ";
        cin>>ch;
 
        switch (ch)
        {
        case 1:
            cout<<"Enter The value  : ";
            cin>>no;
            push(no);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        }
    }
}
 
// Pushing data into stack 
void push(int data)
{
    if (top == NULL)
    {
        top =(struct node *)malloc(1*sizeof(struct node));
        top->ptr = NULL;
        top->info = data;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->ptr = top;
        temp->info = data;
        top = temp;
    }
    count++;
}

//Deleting elements using pop operation
void pop()
{
    top1 = top;
 
    if (top1 == NULL)
    {
        cout<<"\n Error : Trying to pop from empty stack";
        return;
    }
    else
        top1 = top1->ptr;
    cout<<"\n Popped value : "<<top->info<<endl;
    free(top); //To deallocate the memory dynamically, i'm using free function
    top = top1;
    count--;
}
  
// Displaying stack elements
void display()
{
    top1 = top;
 
    if (top1 == NULL)
    {
        cout<<"Stack is empty";
        return;
    }
 
    while (top1 != NULL)
    {
        cout<<top1->info;
        top1 = top1->ptr;cout<<endl;
    }
 }