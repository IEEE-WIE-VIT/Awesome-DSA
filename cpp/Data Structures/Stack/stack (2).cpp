#include <iostream>
using namespace std;
#define MAX 100

class Stack {
public:
    int top;
    int a[MAX];

    Stack()
    {
        top = -1;
    }
    bool push(int x);
    int pop();
    void peek();
    void isEmpty();
};

bool Stack::push(int x)
{
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow";
        return false;
    }
    else {
        a[++top] = x;
        cout << x << " Pushed into stack\n";
        return true;
    }
}

int Stack::pop()
{
    if (top < 0) {
        cout << "Stack Underflow"<<"\n";
        return 0;
    }
    else {
        int x = a[top--];
        return x;
    }
}
void Stack::peek()
{
    if (top < 0) {
        cout << "Stack is Empty"<<"\n";
    }
    else {
        int x = a[top];
        cout<<x<<"\n";
    }
}

void Stack::isEmpty()
{
    if(top<0){
        cout<<"Stack is Empty"<<"\n";
    }
    else{
        cout<<"Stack is not Empty"<<"\n";
    }
}

int main()
{
    int n;
    class Stack s;
    while(1){
        cout<<"1. Push\n";
        cout<<"2. Pop\n";
        cout<<"3. Peek\n";
        cout<<"4. isEmpty\n";
        cout<<"5. Display\n";
        cout<<"Enter your choice=";
        cin>>n;
        if(n==1){
            int no;
            cout<<"Enter the number=";
            cin>>no;
            s.push(no);
        }
        else if(n==2){
            cout<<s.pop()<<" Popped from stack\n";
        }
        else if(n==3){
            s.peek();
        }
        else if(n==4){
            s.isEmpty();
        }
        else if(n==5){
            int i;
            for(i=0;i<=s.top;i++){
                cout<<s.a[i]<<" ";
            }
            cout<<"\n";
        }
        else{
            cout<<"Error!"<<"\n";
        }
    }
    return 0;
}
