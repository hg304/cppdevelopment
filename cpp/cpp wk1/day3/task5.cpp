#include <iostream>

using namespace std;

int main() {
	int a[] = {1,3,2,5,14,8,6,4};
	int n = sizeof(a)/sizeof(int);
	
	cout << "Elements are: ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	
	cout << "\n";
	
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-1; j++) {
			int temp;
			if (a[j] > a[j+1]) {
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	
	cout << "Elements are: ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	
	cout << "\n";
	
	
}
