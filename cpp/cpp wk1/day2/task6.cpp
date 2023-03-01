#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n, count;
	
	cout << "Enter a number: \n";
	cin >> n;
	
	count = 1;
	
	for (int i = n; i > 0; i--) {
		for (j = 0; j < i; j++) {
			cout << count << " ";
			if (i % 2 == 0) {
				count++;
			} else {
				count--;
			}
			
		}
		
		cout << "\n";
		
		
	}
}
