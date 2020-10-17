#include <iostream>
#include <string>
#include <stack>
using namespace std;

int precedence(char op) {
    if (op == '^') {
        return 3;
    } else if (op == '/' || op == '*') {
        return 2;
    } else if (op == '+' || op == '-') {
        return 1;
    }
    return -1;
}

int main() {
    string infix;
    getline(cin, infix);
    cout << "Infix: " << infix << endl;

    string postfix = "";
 
    stack<char> s;
    for (int i = 0; i < infix.length(); i++) {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')) {
            postfix += infix[i];
        } else {
            if (infix[i] == '(') {
                s.push(infix[i]);
            } else if (infix[i] == ')') {
                while (s.top() != '(') {
                    char c = s.top();
                    postfix += c;
                    s.pop();
                }
                s.pop();
            } else {
                while (!s.empty() && s.top() != '(' && precedence(s.top()) >= precedence(infix[i])) {
                    char c = s.top();
                    postfix += c;
                    s.pop();
                }
                s.push(infix[i]);
            }
        }
    }
    while (!s.empty()) {
        char c = s.top();
        postfix += c;
        s.pop();
    }

    cout << "Postfix: " << postfix << endl;
    return 0;
}
