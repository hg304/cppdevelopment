#include <iostream>
#include <cstdlib>

using namespace std;

int smallestnum(int arr[], int n) {
	int found[n+1] = {0};
	int smallest = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > 0 && arr[i] <= n) {
			found[arr[i]] = 1;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (found[i] == 0) {
			smallest = i;
			return smallest;
		}
		return n+1;
	}
	
}

int main() {
	int arr[8] = {2,3,7,6,8,-1,-10,15};
	int n = sizeof(arr)/sizeof(int);
	
	
	cout << smallestnum(arr, n);
	
}
