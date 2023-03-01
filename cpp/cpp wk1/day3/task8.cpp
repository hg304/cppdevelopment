#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int a[] = {11,22,33,44}, b[] = {1,2}, c[] = {32,5,12};
	int asize = sizeof(a)/sizeof(int), bsize = sizeof(b)/sizeof(int), csize = sizeof(c)/sizeof(int);
	int dsize = asize + bsize + csize;
	int d[dsize] = {0};
	
	int largest = max(max(asize, bsize), csize);
	
	int count = 0, dcount = 0;
	
	while (count < largest) {
		if (count < asize) {
			d[dcount] = a[count];
			dcount++; 
		}
		if (count < bsize) {
			d[dcount] = b[count];
			dcount++;
		}
		if (count < csize) {
			d[dcount] = c[count];
			dcount++;
		}
		count++;
	}
	
	for (int i = 0; i < dsize; i++) {
		cout << d[i] << " ";
	}
	cout << "\n";
	
}
