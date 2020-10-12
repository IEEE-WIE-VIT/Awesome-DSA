#include <iostream>
#include "queue.h"
#include "queue.cpp"

using namespace std;

int main()
{
    Queue<int> queue1;
    int ele;
    cout << "Add an element for the head: " << endl;
    cin >> ele;
    queue1.add_end(ele);
    cout << "Add an element for the head: " << endl;
    cin >> ele;
    queue1.add_end(ele);
    cout << "Add an element for the head: " << endl;
    cin >> ele;
    queue1.add_end(ele);
    cout << "Add an element for the head:: " << endl;
    cin >> ele;
    queue1.add_end(ele);
    cout << "Add an element for the head:" << endl;
    cin >> ele;
    queue1.add_end(ele);
    cout << "The list will be printed: " << endl;
    queue1.print();
    cout << "The first item will be removed" << endl << endl;
    queue1.dell();
    cout << "The list will be printed: " << endl;
    queue1.print();
}