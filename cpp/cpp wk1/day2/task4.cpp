#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	
	cout << "Enter a number: \n";
	cin >> n;
	
	for (int i = n; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (i == n) {
				cout << "*";
			}
			if (j == 0) {
				cout <<  "*";
			} else if (j == (i-1)) {
				cout << "*";
			} else {
				cout << " ";
			}
		}
		cout << "\n";
	}
}
