#include <iostream>
#include <stack>
#include <string>
using namespace std;
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '^') {
        return 3;
    } else {
        return -1;  // invalid operator
    }
}
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix;
    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];
        if (isdigit(ch) || isalpha(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') { //PARANTHESIS COMPLETED
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        } else {  //OPERATOR LOGICS USING PRECEDENCES
            while (!s.empty() && s.top() != '(' && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}
int main(){
	cout<<"Enter infix: "<<endl;
	string infix;
	cin>>infix;
	string postfix=infixToPostfix(infix);
	cout<<"Postfix result is: "<<postfix<<endl;
	return 0;
}
