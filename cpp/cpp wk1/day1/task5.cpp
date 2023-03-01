#include <iostream>

using namespace std;

int main() {
	int n, total, count;
	
	cout << "Enter a number: \n";
	cin >> n;
	
	while (n != 0) {
		count += 1;
		total += n % 10;
		n /= 10;
	}
	
	cout << "Number of digits: " << count << "\n";
	cout << "All digits added: "<< total << "\n";
}
