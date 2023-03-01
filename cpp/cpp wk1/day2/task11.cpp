#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	
	cout << "Enter number: \n";
	cin >> n;
	
	for (int i = 1; i <= n*2; i++) {
		for (int j = 1; j <= 2*n-1; j++ ) {
			if (j == n || i == n || j == n+1-i || j == n-1+i) {
				cout << "*";
			} else {
				cout << " ";
			}
		}
		cout << "\n";
	}
	
	
	
}
