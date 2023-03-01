#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n, amount;
	
	cout << "Enter a number: \n";
	cin >> n;
	
	amount = (n*2) - 1;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < amount; j++) {
			if (amount - j <= 5) {
				cout << "*";
			} else {
				cout << " ";
			}
		}
		amount -= 1;
		cout << "\n";
	}
}
