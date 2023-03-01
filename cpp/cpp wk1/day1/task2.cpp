#include <iostream>

using namespace std;

int main() {
	int n;
	char ch;
	
	do {
		
		cout<<"\nWould you like to do this? 1 for yes, 2 for no \n";
		cin>>ch;
		
		switch (ch){
			case '1':
				cout<<"Enter a number: "<<endl;
				cin>>n;
				
				if (n%2 == 0) {
					for (int i = n+2; i>n/2; i--) {
						cout<<i<<" ";
					}
					
					for (int i = 1; i<=n/2; i++) {
						cout<<i<<" ";
					}
					break;
				} else {
					for (int i = n; i>n/2; i--) {
						cout<<i<<" ";
					}
					
					for (int i = 1; i<=n/2; i++) {
						cout<<i<<" ";
					}
					break;
				}
				
			case '2':
				cout<<"Exiting..\n";
				break;
			default:
				cout<<"Invalid choice\n";
		}
		
	} while (ch != '2');
}
