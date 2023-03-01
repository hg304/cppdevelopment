#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
	int flag = 0;
	
	string exp = "{{()}}";
	stack<char> st;
	
	for (int i = 0; i < exp.length(); i++) {
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
			st.push(exp[i]);
		} else {
			if (st.top() == '(' && exp[i] == ')') {
				st.pop();
			} else if (st.top() == '{' && exp[i] == '}') {
				st.pop();
			} else if (st.top() == '[' && exp[i] == ']') {
				st.pop();
			} else {
				break;
			}
		}
	}
	
	if (st.empty()) {
		flag = 1;
	}
	
	if (flag == 0) {
		cout << "Not balanced";
	} else {
		cout << "Balanced";
	}
}
