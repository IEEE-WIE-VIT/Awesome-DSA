#include <iostream>
using namespace std;

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

int length(node *head)
{
    // calculates the length of the linked list
    // basically we are just iterating over the list and counting no of nodes present
    int count(0);
    while (head != NULL)
    {
        count++;
        head = head->next;
    }

    return count;
}

void insertAtMiddle(node *&head, int data, int pos)
{
    if (pos == 0 or head == NULL)
    {
        // corner case
        insertAtHead(head, data);
        return;
    }
    else if (pos > length(head))
    {
        // corner case

        // if the position entered is more than the length of the linkedlist
        // simply insert at tail
        insertAtTail(head, data);
        return;
    }
    else
    {
        // to reach the pos we have to take pos - 1 jumps
        int jumps = 0;
        node *temp = head;
        while (jumps <= pos - 1)
        {
            temp = temp->next;
            jumps++;
        }
        // once we have reached the correct pos to enter
        // create a new node
        node *n = new node(data);
        n->next = temp->next;
        temp->next = n;
    }
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

/* NOTE : In the function insertAtMiddle and insertAtTail 
we have used a node *temp and node *tail instead of using actual head
because as we are passing head by reference and if we use the actual head and change it, that change would be reflected in the orginal head(in the main function) since we have passed it by reference. thus to prevent it and head should always point at the start of linkedlist we are making its copy (temp and tail) and using it 
*/

int main()
{
    // creating a head pointer
    node *head = NULL;

    insertAtMiddle(head, 1, 0);
    print(head);

    insertAtMiddle(head, 0, 0);
    print(head);

    insertAtTail(head, 2);
    print(head);

    insertAtMiddle(head, 3, 4);
    print(head);

    return 0;
}