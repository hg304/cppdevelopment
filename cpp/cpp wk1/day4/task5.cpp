#include<iostream>
#define max 5
using namespace std;
void push(int a[],int &top);
void pop(int a[],int &top);
void display(int a[],int top);
int main()
{
	int a[max],top;
	top=-1;
	int ch;
	do
	{
		cout<<"\n 1 PUSH 2 POP 3 DISPLAY 4 EXIT\n Enter choice = ";
		cin>>ch;
		switch(ch)
		{
			case 1: push(a,top);break;
			case 2: pop(a,top);break;
			case 3: display(a,top);break;
			case 4: break;
		}
	}while(ch!=4);
}
void push(int a[],int &top)
{
	if(top==max-1)
		cout<<"\n Stack overflow \n";
	else
	{
		int ele;
		cout<<"\n enter the ele = ";
		cin>>ele;
		a[++top]=ele;
	}
}
void pop(int a[],int &top)
{
	if(top==-1)
		cout<<"\n Stack underflow \n";
	else
	{
		cout<<"\n Deleting  = "<<a[top--]<<endl;
	}
}
void display(int a[],int top)
{
	if(top==-1)
		cout<<"\n Stack underflow \n";
	else
	{
		cout<<"\n Stack elements \n";
		for(int i=top;i>=0;i--)
			cout<<a[i]<<endl;
	}
}
