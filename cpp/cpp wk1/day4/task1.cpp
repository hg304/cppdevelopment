#include <iostream>

using namespace std;

int main() {
	int a[] = {1,11,33,2,5,4};
	
	int min, minind;
	
	int n = sizeof(a)/sizeof(int);
		
	for (int i = 0; i < (sizeof(a)/sizeof(int)); i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
	
	for(int i=0;i<n-1;i++)
	{
		min = a[i];
		minind = i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<min)
			{
				min = a[j];
				minind = j;
			}
		}
		int temp = a[i];
		a[i] = a[minind];
		a[minind] = temp;
		
	}
	
	for (int i = 0; i < (sizeof(a)/sizeof(int)); i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
}
