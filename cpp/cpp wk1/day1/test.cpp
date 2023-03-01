#include<iostream>
using namespace std;
int main()
{
	int  price=0,qty;
	char ch;
	do
	{
		cout<<"\n1 Paper  (20)\n2 Ink    (10)\n3 Marker (5)\n4 Pen    (3)\n5 Exit"<<endl;
		cout<<"Enter the choice = ";
		cin>>ch;
		
		if(ch>'0' && ch<'5')
		{
			cout<<"\n Enter the quantity = ";
			cin>>qty;
		}			
			
		switch(ch)
		{
			case '1':price += qty *20;
					cout<<"\n PAPER with quantity = "<<qty<<" Price = "<<(qty*20)<<endl;
					break;
			case '2':price += qty *10;
					cout<<"\n INK with quantity = "<<qty<<" Price = "<<(qty*10)<<endl;
					break;
			case '3':price += qty *5;
					cout<<"\n MARKER with quantity = "<<qty<<" Price = "<<(qty*5)<<endl;
					break;
			case '4':price += qty *3;
					cout<<"\n PEN with quantity = "<<qty<<" Price = "<<(qty*3)<<endl;
					break;	
			case '5':cout<<"\n Bill = "<<price<<endl;
					break;
			default:cout<<"\n INVALID CHOICE";		
		}
	}while(ch!='5');
}

