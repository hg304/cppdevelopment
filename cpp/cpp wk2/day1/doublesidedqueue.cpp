#include<iostream>
#define max 8
using namespace std;
void enqueuefront();
void dequeuefront();
void enqueueback();
void dequeueback();
void display();
int a[max],f1,r1,f2,r2;
int main()
{
	f1 = 0, r1 = -1, f2 = max-1, r2 = max;;
	int ch;
	do
	{
		cout<<"\n 1: Enqueue front\n2. Dequeue front\n3. Enqueue back\n4. Dequeue back\n5. Display\n6. Exit\n Enter choice= ";
		cin>>ch;
		cout << "\n";
		switch(ch)
		{
			case 1: 
				enqueuefront();
				break;
			case 2: 
				dequeuefront();
				break;
			case 3: 
				enqueueback();
				break;
			case 4: 
				dequeueback();
				break;
			case 5: 
				display();
				break;
			case 6: 
				break;
			default:
				cout << "Invalid choice \n";
		}
	}while(ch!=6);
}
void enqueuefront()
{
	if(r1 == max-1 || r1+1 == r2)
		cout << "Queue overflow\n";
	else
	{
		int ele;
		cout << "Enter the element: ";
		cin >> ele;
		cout << "\n";
		a[++r1] = ele;
	}	
}
void dequeuefront()
{
	if(f1>r1)
		cout << "Queue underflow\n";
	else
	{
		cout << "The element deleted: " << a[f1] << "\n";
		f1++;
	}
}
void enqueueback() {
	if(r2 == 0 || r2-1 == r1) {
		cout << "Queue overflow\n";
	} else {
		int ele;
		cout << "Enter the element: ";
		cin >> ele;
		cout << "\n";
		a[--r2] = ele;
	}
}
void dequeueback() {
	if (f2<r2) {
		cout << "Queue underflow\n";
	} else {
		cout << "The element deleted: " << a[f2] << "\n";
		f2--;
	}
}
void display()
{
	if(f1>r1 && f2<r2)
		cout<<"\n Queue empty\n";
	else
	{
		cout<<"Front side of Queue: ";
		for(int i=f1;i<=r1;i++) {
			cout<<a[i]<<" ";
		}
		cout << "\n";
		cout << "Back side of Queue: ";
		for (int i = f2;i>=r2;i--) {
			cout << a[i]<<" ";
		}
		cout << "\n";
		
	}
}
