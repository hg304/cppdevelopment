#include<iostream>
using namespace std;
int main()
{
	char s[] = "hello";
	
	char *p;
	p = s;
	
	cout<<"p = " <<p<<" *(p+0) = "<<*(p+0)<<endl;
	cout<<" *(p+1) = "<<*(p+1)<<endl;
	cout<<" *p+1 = "<<*p+1<<endl;
	
	
	
	int a[] = {11,22,33,44};
	int *d;
	d=a;
	
	cout<<*(d+1)<<endl;
	cout<<*d+1<<endl;
	*(d+1) = 88;
	cout<<*(d+1)<<endl;
	cout<<"\n ele\n";
	for(int i=0;i<4;i++)
	{
		*(d+i) = *d+i;
	}
		
	for(int i=0;i<4;i++)
		cout<<a[i]<<endl;
	
}
