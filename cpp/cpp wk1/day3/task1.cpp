#include <iostream>

using namespace std;

int main() {
	int n,sk,flag = 0;
	cout<<"\n Enter the num of elements = ";
	cin>>n;
	
	int a[n];
	
	cout<<"\n enter the ele = ";
	for(int i=0;i<n;i++)
		cin>>a[i];
			
	cout<<"\n The ele = ";
	for(int i=0;i<n;i++)
		cout<<a[i]<<"\t";
		
		
	cout<<"\n Enter the key element = ";
	cin>>sk;
		
	//linear search
	for(int i=0;i<n;i++)
	{
		if(a[i]==sk)
		{
			cout<<"\n Found key at ind = "<<i<<" pos = "<<i+1<<endl;
			flag=1;	
		}
	}	
	
	if(flag==0)
		cout<<"\n search key not found";
		
	
	
	
}
