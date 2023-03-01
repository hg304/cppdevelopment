#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	
	cout << "Enter number: \n";
	cin >> n;
	
	for (int i = 1; i <= 2*n-1; i++) {
		for (int j = 1; j <= 2*n-1; j++) {
			if (j <= n && (i == 1 || i == 2*n-1)) {
				cout << "*";
			} else if (j - i == n - 1 || j + i == 3*n - 1) {
				cout << "*";
			} else {
				cout << " ";
			}
		}
		cout << "\n";
	}
	
	
	
}
