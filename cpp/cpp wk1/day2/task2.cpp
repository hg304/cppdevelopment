#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	
	cout << "Enter a number: \n";
	cin >> n;
	
	while (n > 0) {
		for (int i = n; i > 0; i--) {
			cout << i << " ";
		}
		cout << "\n";
		n--;
	}
}
