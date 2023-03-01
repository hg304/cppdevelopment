#include <iostream>

using namespace std;

int main() {
	int n, rot;
	string choice;
	
	cout << "Enter an number: \n";
	cin >> n;
	
	int a[n];
	
	for (int i = 0; i < n; i++) {
		int temp;
		cout << "Enter element " << i << ": ";
		cin >> temp;
		a[i] = temp;
		cout << "\n";
	}
	
	cout << "Left shift or Right shift? ";
	cin >> choice;
	cout << "\nHow many rotations: ";
	cin >> rot;
	
	while (rot > 0) {
		if (choice == "left") {
			for (int i = 1; i < n; i++) {
				int temp = a[i-1];
				a[i-1] = a[i];
				a[i] = temp;
			}
		} else {
			for (int i = n-1; i > 0; i--) {
				int temp = a[i-1];
				a[i-1] = a[i];
				a[i] = temp;
			}
		}
		
		rot--;
	}
	
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	
	
	
}
