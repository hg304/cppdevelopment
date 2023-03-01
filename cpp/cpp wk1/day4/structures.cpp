#include<iostream>
#include<string.h>
using namespace std;
struct Student
{
	int id;
	char name[20];
};
void display(Student s)
{
	cout<<"ID  = "<<s.id<<endl;
	cout<<"NAME = "<<s.name<<endl;
}
void getdata(Student *x)
{
	cout<<"\n Enter id  = ";
	cin>>x->id;
	cout<<"\n Enter name  = ";
	cin>>x->name;
}
int main()
{
	Student s[3];
	for(int i=0;i<3;i++)
	{
		getdata(&s[i]);
		display(s[i]);
	}	
}
