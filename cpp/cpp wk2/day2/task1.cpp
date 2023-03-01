#include <iostream>
#include "singlylinked.h"

using namespace std;

int main() {
	head = NULL;
	count = 0;
	int ch, ele, pos, a, b;
	Node* n;
	do {
		cout << "\n1. Insert Begin\n2. Insert End\n3. Insert at a Position\n4. Delete Begin\n5. Delete End\n6. Delete at a position\n7. Get value from position\n8. Get largest value\n9. Get smallest value\n10. Swap Alternates\n11. Display list\n12. Exit";
		cout << "\nEnter choice: ";
		cin >> ch;
		cout << "\n";
		switch(ch) {
			case 1:
				cout << "Enter the element: ";
				cin >> ele;
				cout << "\n";
				insertBegin(ele);
				break;
			case 2:
				cout << "Enter the element: ";
				cin >> ele;
				cout << "\n";
				insertEnd(ele);
				break;
			case 3:
				cout << "Enter the element: ";
				cin >> ele;
				cout << "\n";
				
				cout << "Enter the position: ";
				cin >> pos;
				cout << "\n";
				insertAtPos(ele, pos);
				break;
			case 4:
				deleteBegin();
				break;
			case 5:
				deleteEnd();
				break;
			case 6:
				cout << "Enter a position: ";
				cin >> pos;
				cout << "\n";
				deleteAtPos(pos);
				break;
			case 7:
				cout << "Enter the position: ";
				cin >> pos;
				cout << "\n";
				n = at(pos);
				if (n -> data == -1) {
					cout << "Position was not found";
				} else {
					cout << "The element at position " << pos << " is " << n -> data << "\n";
				}
				break;
			case 8:
				n = max();
				cout << "The largest element in the list is " << n -> data << "\n";
				break;
			case 9:
				n = min();
				cout << "The smallest element in the list is " << n -> data << "\n";
				break;
			case 10:
				swapalternate();
				break;
			case 11:
				display();
				break;
			case 12:
				cout << "Enter the starting position: ";
				cin >> a;
				cout << "\n";
				cout << "Enter the ending position: ";
				cin >> b;
				cout << "\n";
				sort(a, b);
				break;
			case 13:
				break;
			default:
				cout << "Invalid choice\n";
		}
	} while (ch != 13);
}
