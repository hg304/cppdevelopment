#include <iostream>

using namespace std;

struct Node {
	int data;
	struct Node *next;
};

Node *head;
int count;

Node* createNode(int ele) {
	Node *temp = new Node();
	temp -> data = ele;
	temp -> next = NULL;
}

Node* at(int pos) {
	if (count == 0 || (pos < count && pos > count)) {
		return NULL;
	}
	Node* ptr = head;
	int tempcount = 1;
	while (tempcount != pos) {
		ptr = ptr -> next;
		tempcount++;
	}
	
	return ptr;
}

Node* max() {
	if (head == NULL) {
		cout << "There are no elements in the list\n";
	}
	Node* ptr = head;
	Node* biggest = head;
	while (ptr != NULL) {
		if (biggest -> data < ptr -> data) {
			biggest = ptr;
		}
		ptr = ptr -> next;
	}
	
	return biggest;
	
}

Node* min() {
	if (head == NULL) {
		cout << "There are no elements in the list\n";
	}
	Node* ptr = head;
	Node* smallest = head;
	while (ptr != NULL) {
		if (smallest -> data > ptr -> data) {
			smallest = ptr;
		}
		ptr = ptr -> next;
	}
	
	return smallest;
}

void insertBegin(int ele) {
	Node *temp = createNode(ele);
	temp -> next = head;
	head = temp;
	count++;	
}

void insertEnd(int ele) {
	Node *temp = createNode(ele);
	Node *ptr = head;
	while (ptr -> next != NULL) {
		ptr = ptr -> next;
	}
	ptr -> next = temp;
	count++;
}

void insertAtPos(int ele, int pos) {
	if (pos == 1) {
		insertBegin(ele);	
	} else if (pos == count + 1) {
		insertEnd(ele);
	} else if (pos > 1 && pos < count + 1) {
		int tempcount = 1;
		Node *temp = createNode(ele);
		Node *ptr = head;
		while (tempcount != pos - 1) {
			ptr = ptr -> next;
			tempcount++;
		}
		Node *temp2 = ptr -> next;
		temp -> next = temp2;
		ptr -> next = temp;
		count++;
	} else {
		cout << "\nIncorrect position";
	}
}

void deleteBegin() {
	if (head == NULL) {
		cout << "There are no elements in the list";
	} else {
		Node* temp = head;
		head = head -> next;
		temp -> data = 0;
		temp -> next = NULL;
		delete temp;
		count--;
	}
}

void deleteEnd() {
	if (head -> next == NULL) {
		head -> data = 0;
		count--;
	}

	Node *ptr = head;
	while (ptr -> next -> next != NULL) {
		ptr = ptr -> next;
	}
	Node* temp = ptr -> next;
	temp -> data = 0;
	delete temp;
	ptr -> next = NULL;
	count--;
}

void deleteAtPos(int pos) {
	if (pos == 1) {
		deleteBegin();	
	} else if (pos == count + 1) {
		deleteEnd();
	} else if (pos > 1 && pos < count + 1) {
		int tempcount = 1;
		Node *ptr = head;
		while (tempcount != pos - 1) {
			ptr = ptr -> next;
			tempcount++;
		}
		Node *temp = ptr -> next;
		ptr -> next = ptr -> next -> next;
		temp -> data = 0;
		temp -> next = NULL;
		delete temp;
		count--;
	} else {
		cout << "\nIncorrect position";
	}
}

void swapalternate() {
	if (head == NULL) {
		cout << "There are no elements in the list\n";
	} else {
		int i = 1;
		Node* ptr = head;
		Node* temp, temp2;
		while (ptr != NULL) {
			if (i % 2 == 0) {
				temp -> next = ptr -> next;
				ptr -> next = temp;
			}
			temp = ptr;
			ptr = ptr -> next;
		}
	}
}

sort(int a, int b) {
	Node *p1 = head, *p2 = head, *temp, *min;
	
	for (int i = 1; i < a; p1 = p1 -> next; i++);
	for (int i = 1; i < b; p2 = p2 -> next; i++);
	
	while (p1 != p2) {
		min = p1;
		temp = p1 -> next;
		while (temp != p2 -> next) {
			if ()
		}
	}
}

void display()
{
	if(head == NULL)
		cout<<"No elements in the list \n";
	else
	{
		cout << "List ele = \n";
		for (Node *p= head; p != NULL; p = p -> next)
		{
			cout << p -> data << " --> ";
		}
	}
}
