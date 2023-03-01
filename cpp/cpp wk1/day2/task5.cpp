#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	
	cout << "Enter a number: \n";
	cin >> n;
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n * 2; ++j) {
			if (j <= i) {
				cout << j;
			}
			else if (j > 2 * n - i) {
				cout << 2 * n - j + 1;
			}
			else {
				cout << ' ';
			}
		}
		cout << endl;
	}
}
