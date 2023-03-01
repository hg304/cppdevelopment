#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	int temp = 0;
	int count = 0;
	int x = 0;
	
	cout << "Enter a number: \n";
	cin >> n;
	
	while (n != 0) {
		temp = n % 10;
		x = x * 10 + temp;
		n /= 10;
	}
	
	cout << "New number: " << x;
}
