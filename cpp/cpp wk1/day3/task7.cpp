#include <iostream>

using namespace std;

int main() {
	int a[20] = {0};
	int choice;
	int length = sizeof(a)/sizeof(int);
	
	int counter = 0;
	
	do {
		cout << "Pick an option:\n1. Insert element\n2. Delete element\n3.Exit \n";
		cin >> choice;
		cout << "\n";
		
		switch (choice) {
			int pos;
			case 1:
				int num;
				if (counter != length) {
					cout << "Number of elements: " << counter << "\n";
					cout << "Enter a number: ";
					cin >> num;
					cout << "\n";
					if (a[0] == 0 || a[1] == 0) {
						if (a[0] == 0) {
							a[0] = num;
						} else {
							a[1] = a[0];
							a[0] = num;
						}
						counter++;
					} else {
						cout << "Enter a position: ";
						cin >> pos;
						cout << "\n";
						if (pos < counter) {
							for (int i = counter + 1; i > pos-1; i--) {
								a[i] = a[i-1];
							}
							
							a[pos-1] = num;
							counter++;
						} else {
							cout << "Invalid position";
						}
						
					}
					
					cout << "Elements in array are: ";
					for (int i = 0; i < counter; i++) {
						cout << a[i] << " ";
					}
			} else {
				cout << "No more space left in the array\n";
			}
				break;
			
			case 2:
				cout << "Number of elements: " << counter << "\n";
				cout << "Enter the position you want to delete: ";
				cin >> pos;
				cout << "\n";
				for (int i = pos-1; i <= counter; i++) {
					a[i] = a[i+1];
					if (i == counter) {
						a[i+1] = 0;
					}
				}
				counter--;
				
				cout << "Elements in array are: ";
				for (int i = 0; i < counter; i++) {
					cout << a[i] << " ";
				}				
				break;
				
			case 3:
				break;
			default:
				cout << "\nInvalid";
		}
		
	} while (choice != 3);
	
	
	
	
}
