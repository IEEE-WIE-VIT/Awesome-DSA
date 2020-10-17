#include <iostream>
#include <string>
#include <stack>
using namespace std;

// We assume input is a valid postfix expression with only operands (a-z, A-Z) and operators (+, -, *, /, ^)
// Input expression should not have any parantheses

bool is_operator(char x) {
	switch (x) {
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
			return true;
	}
	return false;
}

string convert_to_infix(string postfix) {
	stack<string> s;

	int length = postfix.length();

	for (int i = 0; i < length; i++) {
		if (is_operator(postfix[i])) {
			string op1 = s.top();
			s.pop();
			string op2 = s.top();
			s.pop();

			string temp = "(" + op2 + postfix[i] + op1 + ")";
			s.push(temp);
		} else {
			s.push(string(1, postfix[i]));
		}
	}

	return s.top();
}

int main() {
	string postfix;
        getline(cin, postfix);
	cout << "Postfix: " << postfix << endl;

	string infix = convert_to_infix(postfix);
	cout << "Infix: " << infix << endl;

	return 0;
}
