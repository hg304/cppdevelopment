#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n, digits;
	int temp = 0;
	int x = 0;
	
	cout << "Enter a number: \n";
	cin >> n;
	
	digits = int(log10(n)+1);
	
	for(int i = digits; i>1; i-=2)
	{
		temp = int(n/pow(10,i-2));
		
		x = x*10;
		x += temp%10;
		temp = temp/10;
		x = x*10;
		x += temp%10;
	}
	if(digits%2==1)
	{
		x = x*10;
		x += n%10;
	}
	
	cout << "Changed: " << x << "\n";
}
