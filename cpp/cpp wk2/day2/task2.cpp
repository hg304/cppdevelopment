#include <iostream>
#include "linkedlistproduct.h"

using namespace std;

int main() {
	int ch, id, price, category;
	string name;
	
	do {
		cout << "1. Add product to list\n2. Remove last product in list\n3. Display a product\n4. Show total price of all products\n5. Display all products\n6. Arrange products by category\n7. Exit\n";
		cout << "Enter choice: ";
		cin >> ch;
		cout << "\n";
		
		switch(ch) {
			case 1:
				cout << "Enter the id of the product: ";
				cin >> id;
				cout << "\n";
				
				cout << "Enter the name of the product: ";
				cin >> name;
				cout << "\n";
				
				cout << "Enter the price of the product: ";
				cin >> price;
				cout << "\n";
				
				cout << "Enter the category of the product: ";
				cin >> category;
				cout << "\n";
				push_back(id, name, price, category);
				break;
			case 2:
				pop_back();
				break;
			case 3:
				cout << "Enter the id of the product you wish to find: ";
				cin >> id;
				cout << "\n";
				displayProduct(id);
				break;
			case 4:
				cout << "The total price of all products currently is " << calculateTotal() << " pounds.\n";
				break;
			case 5:
				displayAll();
				break;
			case 6:
				sortProducts();
				break;
			case 7:
				break;
			default:
				cout << "\nInvalid";
		}
	} while (ch != 7);
}
