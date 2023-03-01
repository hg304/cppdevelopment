#include <iostream>
#include <cmath>

using namespace std;

bool checkvis(int a[], int k) {
	for (int i = 0; i < (sizeof(a)/sizeof(int)); i++) {
		if (a[i] == k) {
			return true;
		}
	}
	return false;
}

int main() {
	
	int a[] = {11,4,2,11,33,4,55,66,77,2,4,4};
	
	/*int i,j,k;
	
	for (int i = 1; i < n; i++) {
		k = a[i];
		j = i - 1;
		while (j >= 0 && a[j]>k) {
			a[j+1] = a[j];
			j--;
		}
		a[j+1]=k;
	}*/
	
	int visited[10] = {0};
	int vcount = 0;
	
	for (int i = 0; i < (sizeof(a)/sizeof(int)); i++) {
		int temp = 0;
		if (checkvis(visited, a[i]) == true) {
			continue;
		} else {
			visited[vcount] = a[i];
			vcount++;
			for (int j = 0; j < (sizeof(a)/sizeof(int)); j++) {
				if (a[i] == a[j]) {
					temp += 1;
				}
			}
			cout << a[i] << " " << temp << "\n";
		}
		
	}
	
}
