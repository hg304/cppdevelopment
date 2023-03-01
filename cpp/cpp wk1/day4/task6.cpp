#include<iostream>
#define max 5
using namespace std;
void push();
void pop();
void display();
int a[max],top1,top2;
int main()
{
	top1=-1;
	top2=max;
	int ch;
	do
	{
		cout<<"\n 1 PUSH 2 POP 3 DISPLAY 4 EXIT\n Enter choice = ";
		cin>>ch;
		switch(ch)
		{
			case 1: push();break;
			case 2: pop();break;
			case 3: display();break;
			case 4: break;
		}
	}while(ch!=4);
}
void push()
{
	if(top1==top2-1)
		cout<<"\n Stack overflow \n";
	else
	{
		int ch1;
		cout<<"\n 1Bottom up 2 Top bottom \n Enter choice = ";
		cin>>ch1;
		int ele;
		cout<<"\n enter the ele = ";
		cin>>ele;
		switch(ch1)
		{
			case 1:a[++top1]=ele;break;
			case 2:a[--top2]=ele;break;
			default:cout<<"\n invalid choice\n";
		}
	}
}
void pop()
{
	int ch1;
	cout<<"\n 1Bottom up 2 Top bottom \n Enter choice = ";
	cin>>ch1;
	switch(ch1)
	{
		case 1:if(top1==-1)
					cout<<"\n Stack underflow from bottom \n";
				else
				{
					cout<<"\n Deleted element = "<<a[top1--];	
				}
				break;
		case 2:if(top2==max)
					cout<<"\n Stack underflow from top \n";
				else
				{
					cout<<"\n Deleted element = "<<a[top2++];	
				}break;
		default:cout<<"\n invalid choice\n";
	}		
	
}
void display()
{
	if(top1==-1)
		cout<<"\n Stack empty from bottom \n";
	else
	{
		cout<<"\n Elements = "<<endl;
		for(int i=top1;i>=0;i--)
			cout<<a[i]<<endl;	
	}
	if(top2==max)
		cout<<"\n Stack empty from top \n";
	else
	{
		cout<<"\n Elements = "<<endl;
		for(int i=max-1;i>=top2;i--)
			cout<<a[i]<<endl;
	}
}bottom]=ele;
	}
}
void pop_down(int a[], int &bottom)
{
	if(bottom == -1)
		cout<<"\n Stack underflow \n";
	else
	{
		cout<<"\n Deleting  = "<<a[bottom++]<<endl;
	}
}

void display_up(int a[], int top)
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

void display_down(int a[], int bottom)
{
	if(bottom == max)
		cout<<"\n Stack underflow \n";
	else
	{
		cout<<"\n Stack elements \n";
		for(int i=bottom;i<=max;i--)
			cout<<a[i]<<endl;
	}
}
