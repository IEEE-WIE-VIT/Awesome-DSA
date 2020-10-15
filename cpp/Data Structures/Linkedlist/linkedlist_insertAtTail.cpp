#include <iostream>
using namespace std;
#define endl '\n'

class node
{

public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};

void insertAtHead(node *&head, int data)
{
    if (head == NULL)
    {
        head = new node(data);
        return;
    }

    node *n = new node(data);
    n->next = head;
    head = n;

    return;
}

void insertAtTail(node *&head, int data)
{
    if (head == NULL)
    {
        // corner case
        // insert first node basically insertAtHead(head,data);
        head = new node(data);
        return;
    }
    // create a tail pointer of node type
    node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    // once reached at the end of the linkedlist
    // create new node
    tail->next = new node(data);
    return;
}

void print(node *head)
{

    while (head != NULL)
    {
        cout << head->data << "<--";
        head = head->next;
    }
    cout << endl;
}

/* NOTE : In the function insertAtTail 
we have used a node *tail instead of using actual head
because as we are passing head by reference and if we use the actual head and change it, that change would be reflected in the orginal head(in the main function) since we have passed it by reference. thus to prevent it and head should always point at the start of linkedlist we are making its copy (temp and tail) and using it 
*/

int main()
{
    // creating a head pointer
    node *head = NULL;
    insertAtHead(head, 1);
    print(head);

    insertAtHead(head, 0);
    print(head);

    insertAtTail(head, 2);
    print(head);

    insertAtTail(head, 3);
    print(head);

    return 0;
}