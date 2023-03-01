#include<iostream>
#include<string.h>
using namespace std;
struct Contact
{
	int id;
	char name[20], email[30];
};

void addContact(Contact *c) {
	cout << "Enter ID: ";
	cin >> c -> id;
	cout << "\n";
	
	cout << "Enter Name: ";
	cin >> c -> name;
	cout << "\n";
	
	cout << "Enter Email: ";
	cin >> c -> email;
	cout << "\n";
}

void deleteContact(Contact (*c)[10], int counter) {
	int id, pos = -1;
	cout << "Enter the id of student: ";
	cin >> id;
	cout << "\n";
	
	for (int i = 0; i < counter; i++) {
		if (id == c[i] -> id) {
			pos = i;
			break;
		}
	}
	
	if (pos != -1) {
		for (int i = pos; i < counter + 1; i++) {
			*c[i] = *c[i+1];
		}
	} else {
		cout << "Contact not found\n";
	}
}

void updateContact(Contact (*c)[10], int counter) {
	int id, flag = 0;
	Contact *p;
	cout << "Enter the id of student: ";
	cin >> id;
	cout << "\n";
	
	for (int i = 0; i < counter; i++) {
		if (id == c[i] -> id) {
			flag = 1;
			p = c[i];
			break;
		}
	}
	
	if (flag == 1) {
		cout << "Enter new id: ";
		cin >> p -> id;
		cout << "\n";
		
		cout << "Enter new name: ";
		cin >> p -> name;
		cout << "\n";
		
		cout << "Enter new email: ";
		cin >> p -> email;
		cout << "\n";
	} else {
		cout << "Contact not found\n";
	}
}

void searchContact(Contact (*c)[10], int counter) {
	int id, flag = 0;
	cout << "Enter the id of student: ";
	cin >> id;
	cout << "\n";
	
	for (int i = 0; i < counter; i++) {
		if (id == c[i] -> id) {
			flag = 1;
			break;
		}
	}
	
	if (flag == 1) {
		cout << "Contact was found\n";
	} else {
		cout << "Contact not found\n";
	}
}

void displayById(Contact (*c)[10], int counter) {
	int id, flag = 0;
	Contact *p;
	cout << "Enter the id of student: ";
	cin >> id;
	cout << "\n";
	
	for (int i = 0; i < counter; i++) {
		if (id == (c[i] -> id)) {
			flag = 1;
			p = c[i];
			break;
		}
	}
	
	if (flag == 1) {
		cout << "ID: " << p -> id << "\n";
		cout << "Name: " << p -> name << "\n";
		cout << "Email: " << p -> email << "\n";
	} else {
		cout << "Contact not found\n";
	}
}

void displayAll(Contact (*c)[10], int counter) {
	for (int i = 0; i < counter; i++) {
		cout << "ID: " << c[i] -> id << "\n";
		cout << "Name: " << c[i] -> name << "\n";
		cout << "Email: " << c[i] -> email << "\n";
	}
}

int main() {
	Contact c[10] = {0};
	int choice = 0, counter = 0;
	
	
	do {
		cout << counter << " contacts in the system\n";
		cout << "1. Insert\n2. Delete\n3. Update\n4. Search by id\n5. Display contact by id\n6. Display all Contacts\n ";
		cin >> choice;
		
		switch (choice) {
			case 1:
				addContact(&c[counter]);
				counter++;
				break;
			case 2:
				deleteContact(&c, counter);
				counter--;
				break;
			case 3:
				updateContact(&c, counter);
				break;
			case 4:
				searchContact(&c, counter);
				break;
			case 5:
				displayById(&c, counter);
				break;
			case 6:
				displayAll(&c, counter);
				break;
			case 7:
				break;
			default:
				cout << "\nInvalid\n";
		}
	} while (choice != 7);	
	
}
