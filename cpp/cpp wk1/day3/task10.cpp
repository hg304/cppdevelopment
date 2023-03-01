#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int row, col;
	
	cout << "Enter number of rows: ";
	cin >> row;
	cout << "\n";
	
	cout << "Enter number of columns: ";
	cin >> col;
	cout << "\n";
	
	int choice = 0;
	int a[row][col];
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << "Enter element for " << i+1 << "," << j+1 << ": ";
			cin >> a[i][j];
			cout << "\n";
		}
	}
	
	do {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cout << a[i][j] << " ";
			}
			cout << "\n";
		}
		
		cout << "1. Calculate sum of rows\n2. Calculate sum of cols\n3.Calculate sum of diagonals\n4. Exit\n";
		cin >> choice;
		cout << "\n";
		
		switch (choice) {
			case 1:
				for (int i = 0; i < row; i++) {
					int temp = 0;
					for (int j = 0; j < col; j++) {
						temp += a[i][j];
						cout << a[i][j] << " ";
					}
					cout << "= " << temp << "\n";
				}
				cout << "\n";
				break;
			case 2:
				for (int i = 0; i < row; i++) {
					int temp = 0;
					for (int j = 0; j < col; j++) {
						temp += a[j][i];
						cout << a[j][i] << " ";
					}
					cout << "= " << temp << "\n";
				}
				cout << "\n";
				break;
			case 3:
				for (int i = 0; i < row; i++) {
					int temp = 0;
					for (int j = 0; j < col; j++) {
						if (i == j) {
							temp += a[i][j];
							cout << a[i][j] << " ";
						}
					}
					cout << "= " << temp << "\n";
				}
				cout << "\n";
				
				for (int i = 0; i < row; i++) {
					int temp = 0;
					for (int j = 0; j < col; j++) {
						if ((i + j) == (col - 1- i)) {
							temp += a[i][j];
							cout << a[i][j] << " ";	
						}
					}
					cout << "= " << temp << "\n";
				}
				cout << "\n";
				break;
			case 4:
				break;
			default:
				cout << "\nInvalid";
		}
	} while (choice != 4);
	
	
}
