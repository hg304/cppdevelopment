#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	
	cout << "Enter number: \n";
	cin >> n;
	
	for (int i = 1; i < n*2 - 1; i++) {
		for (int j = 1; j < 4*n-3; j++ ) {
			if (i + j == n+1 || j == n-1+i || i == 5*n-3+i ) {
				cout << "*";
			} else {
				cout << " ";
			}
		}
		cout << "\n"
	}
	
	
	
}
