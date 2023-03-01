#include <iostream>

using namespace std;

int main() {
	int k, lo = 0, flag = 0, mid, hi;
	
	lo = 0;
	int a[] = {11,22,33,44,55,66};
	hi = sizeof(a)/sizeof(int);
	
	cout << "What element do you want to find: ";
	cin >> k;
	cout << "\n";
	
	
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		if (a[mid] == k) {
			flag = 1;
			break;
		} else if (k < a[mid]) {
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	
	if (flag == 1) {
		cout << "Element has been found";
	} else {
		cout << "Element has not been found";
	}
	
	
}
