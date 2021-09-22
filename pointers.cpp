#include<iostream>
using namespace std;
int main()
{
	int arr[3][3];
	int i,j;
	int *ptr;
	cout<<"Enter the elements of the array:\n";
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cin>>arr[i][j];
		}
	}
	//ptr=arr;
	cout<<"Elements of the array and addresses are:\n";
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
           cout<<"\t"<<((arr+i)+j);
		}
		cout<<"\n";
	}
	return 0;
}

