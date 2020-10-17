#include <iostream>
#include <string>
#include <stack>
using namespace std;

// We assume input is a valid prefix expression with only operands (a-z, A-Z) and operators (+, -, *, /, ^)
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

string convert_to_infix(string prefix) {
	stack<string> s;

	int length = prefix.length();

	for (int i = length - 1; i >= 0; i--) {
		if (is_operator(prefix[i])) {
			string op1 = s.top();
			s.pop();
			string op2 = s.top();
			s.pop();

			string temp = "(" + op1 + prefix[i] + op2 + ")";
			s.push(temp);
		} else {
			s.push(string(1, prefix[i]));
		}
	}

	return s.top();
}

int main() {
	string prefix;
        getline(cin, prefix);
	cout << "Prefix: " << prefix << endl;

	string infix = convert_to_infix(prefix);
	cout << "Infix: " << infix << endl;

	return 0;
}
