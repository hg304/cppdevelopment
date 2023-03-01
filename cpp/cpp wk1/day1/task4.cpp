#include <iostream>

using namespace std;

int main() {
	int n;
	int total;
	
	cout << "Enter a number: \n";
	cin >> n;
	
	for (int i = 0; i < n.length; i++) {
		cout << n[i] << "\n";
		total += n[i];
	}
	
	cout << total << "\n";
}
