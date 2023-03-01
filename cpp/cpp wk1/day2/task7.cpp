#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n, count;
	
	cout << "Enter a number: \n";
	cin >> n;
	
	count = 1;
	
	for (int i = n; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			cout << count << " ";
			
			if (j != i-1) {
				if (i % 2 == 0) {
					count -= 1;
				} else {
					count += 1;
				}
			}
			
		}
		count += 1;
		cout << "\n";
		
		
	}
}
