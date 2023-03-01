#include <iostream>

using namespace std;

int main() {
	int a[20] = {0};
	
	int counter = 0;
	
	while (counter < 20) {
		int pos, num;
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
			
			for (int i = counter + 1; i > pos-1; i--) {
				a[i] = a[i-1];
			}
			
			a[pos-1] = num;
			counter++;
			
		}
		
		cout << "Elements in array are: ";
		for (int i = 0; i < counter; i++) {
			cout << a[i] << " ";
		}
		
	}
	
	
}
