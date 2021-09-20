#include<iostream>
#include<string>
using namespace std;
  struct book 
    {
        string name; 
        string author;
	int year;
	int n;        
        void enterdetails();
        void printdetails();
    };
    
    void enterdetails(book arr[],int n)
	{
	cin.ignore();
	for(int i=0;i<n;i++)
	{
	cout<<"Enter the details of Book "<<(i+1)<<"\n";
	cout<<"Enter the name of the book: ";
	cin.ignore();
	getline(cin,arr[i].name);
	cout<<"Enter the name of Author: ";
	cin.ignore();
	getline(cin,arr[i].author);
	cout<<"Enter the year of Publishing: ";
	cin.ignore();
	cin>>arr[i].year;
       }
     }   
	void printdetails(book arr[],int n)
	{
	cout<<"\n";
	cin.ignore();
	for(int i=0;i<n;i++)
	{
	cout<<"Details of the book are:\n";
	cout<<"\nName of the book: ";
	cout<<arr[i].name;
	cout<<"\nName of Author: ";
	cout<<arr[i].author;
	cout<<"\nYear of Publishing: ";
	cout<<arr[i].year;
       }
	} 
    int main()
    { 
	 int n;
	 book arr[10];
	 cout<<"Enter the number of books: ";
	 cin>>n;
	 enterdetails(arr,n);
	 printdetails(arr,n);
    }
