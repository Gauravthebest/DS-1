//Display Doubly Linked List
#include<iostream>
#include<stdlib.h>
using namespace std;
struct Dnode
{
	int data;
	struct Dnode *prev;
	struct Dnode *next;
}*L=NULL,*R=NULL;

void printlist(struct Dnode *L)
{
	struct Dnode *ptr=L;
	while(ptr!=NULL)
	{
		cout<<"Element:"<<ptr->data<<"\n";
		ptr=ptr->next;
	}
}
int main()
{
	struct Dnode *n1,*n2,*n3;
	n1=new Dnode();
	n2=new Dnode();
	n3=new Dnode();
	
	L=n1;
	n1->data=10;
	n1->prev=NULL;
	n1->next=n2;
	
	n2->data=20;
	n2->prev=n1;
	n2->next=n3;
	
	n3->data=30;
	n3->prev=n2;
	n3->next=NULL;
	R=n3;
	
	printlist(L);
}
