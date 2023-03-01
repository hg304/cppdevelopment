#include <iostream>

using namespace std;

int main() {
	int k, lo = 0, flag = 0, mid, occurrences = 0, hi;
	
	lo = 0;
	int a[] = {22,22,22,44,55,66};
	hi = sizeof(a)/sizeof(int);
	
	cout << "What element do you want to find: ";
	cin >> k;
	cout << "\n";
	
	
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		if (a[mid] == k) {
			cout << "Found at " << mid << "\n";
			int midlow = mid - 1;
			while (midlow >= lo && a[midlow] == k) {
				cout << "Found at " << midlow << "\n";
				midlow--;
			}
			int midhi = mid - 1;
			while (midhi <= hi && a[midhi] == k) {
				cout << "Found at " << midhi << "\n";
				midhi++;
			}
			break;
		} else if (k < a[mid]) {
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	
	if (occurrences > 0) {
		cout << "Element has been found at " << occurrences << " points";
	} else {
		cout << "Element has not been found";
	}
	
	
}
