#include <iostream>

using namespace std;

int main() {
	char a[100];
	int space[100];
	int count = 0;
	char b[100];
	
	cout << "Input some text: ";
	gets(a);
	
	int n = (sizeof(a)/sizeof(int));
	
	for (int i = 0; i < n- 1; i++) {
		if (a[i] == ' ' && a[i+1] == ' ') {
			continue;
		} else {
			b[i] = a[i];
		}
	}
	
	
	
	cout << "\nThe string entered is: " << b;
	
	
}
