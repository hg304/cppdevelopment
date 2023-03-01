#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n, digits;
	int temp = 0;
	
	cout << "Enter a number: \n";
	cin >> n;
	
	digits = int(log10(n)+1);
	
	int first = n % 10;
	first *= int(pow(10,digits-1));
	n /= 10;
	
	first += n;
	
	
	
	
	cout << "Changed: " << first << "\n";
}
