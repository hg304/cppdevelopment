#include <iostream>
#include <string>

using namespace std;

struct Product {
	int pid;
	string pname;
	int pprice;
	int pcategory;
	struct Product *next;
};

Product *head;
int count;

Product* createProduct(int id, string name, int price, int category) {
	Product *temp = new Product();
	temp -> pid = id;
	temp -> pname = name;
	temp -> pprice = price;
	temp -> pcategory = category;
	temp -> next = NULL;
}

void push_back(int id, string name, int price, int category) {
	Product *temp = createProduct(id, name, price, category);
	if (head == NULL) {
		head = temp;
	} else {
		Product *ptr = head;
		while (ptr -> next != NULL) {
			ptr = ptr -> next;
		}
		ptr -> next = temp;
	}	
	count++;
}

void pop_back() {
	Product *ptr = head;
	if (ptr -> next == NULL) {
		cout << "The following product has been deleted: \n";
		cout << "ID: " << head -> pid << "\nName: " << head -> pname << "\nPrice: £" << head -> pprice << "\nCategory: " << head -> pcategory << "\n";
		
		head -> pid = 0;
		head -> pname = "";
		head -> pprice = 0;
		head -> pcategory = 0;
		count--;
		
	}

	while (ptr -> next != NULL) {
		ptr = ptr -> next;
	}
	Product* temp = ptr;
	cout << "The following product has been deleted: \n";
	cout << "ID: " << temp -> pid << "\nName: " << temp -> pname << "\nPrice: £" << temp -> pprice << "\nCategory: " << temp -> pcategory << "\n";
	temp -> pid = 0;
	temp -> pname = "";
	temp -> pprice = 0;
	temp -> pcategory = 0;
	delete temp;
	ptr -> next = NULL;
	count--;
}

void displayProduct(int id) {
	Product* ptr = head;
	int flag = 0;
	while (ptr != NULL) {
		if (id == ptr -> pid) {
			flag = 1;
			break;
		}
		ptr = ptr -> next;
	}
	if (flag == 0) {
		cout << "Product with corresponding id not found\n";
	} else {
		cout << "Product is found\n";
		cout << "ID: " << ptr -> pid << "\nName: " << ptr -> pname << "\nPrice: £" << ptr -> pprice << "\nCategory: " << ptr -> pcategory << "\n";
	}
}

void displayAll() {
	Product *ptr = head;
	cout << "There are currently " << count << " products in the list\n";
	while (ptr != NULL) {
		cout << "ID: " << ptr -> pid << "\nName: " << ptr -> pname << "\nPrice: £" << ptr -> pprice << "\nCategory: " << ptr -> pcategory << "\n";	
		ptr = ptr -> next;
	}
}

int calculateTotal() {
	int total = 0;
	Product *ptr = head;
	
	while (ptr != NULL) {
		total += ptr -> pprice;
		ptr = ptr -> next;
	}
	
	return total;
	
}

void sortProducts() {
	Product *ptr = head -> next;
	Product *prev = head;
	while (prev != NULL) {
		while (ptr != NULL) {
			if (prev -> pcategory > ptr -> pcategory) {
				int id = prev -> pid;
				string name = prev -> pname;
				int price = prev -> pprice;
				int category = prev -> pcategory;
				
				prev -> pid = ptr -> pid;
				prev -> pname = ptr -> pname;
				prev -> pprice = ptr -> pprice;
				prev -> pcategory = ptr -> pcategory;
				
				ptr -> pid = id;
				ptr -> pname = name;
				ptr -> pprice = price;
				ptr -> pcategory = category;
			}
			ptr = ptr -> next;
		}
		prev = prev -> next;
	}
	
}
