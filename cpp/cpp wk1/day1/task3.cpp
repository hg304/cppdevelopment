#include <iostream>

using namespace std;

int main() {
	int n;
	
	
	cout<<"Enter number: ";
	cin>>n;
	
	for (int i = 0, j = 1; j <= n; j++) {
		i += j;
		cout<<i<<" ";
	}
	
}
