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

        head = new node(data);
        return;
    }

    node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    tail->next = new node(data);
    return;
}

int length(node *head)
{

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
        insertAtHead(head, data);
        return;
    }
    else if (pos > length(head))
    {
        insertAtTail(head, data);
        return;
    }
    else
    {

        int jumps = 0;
        node *temp = head;
        while (jumps <= pos - 1)
        {
            temp = temp->next;
            jumps++;
        }

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

void createLinkedList(node *&head)
{
    int data;
    while (cin >> data)
    {
        insertAtHead(head, data);
    }
    return;
}

int main()
{
    freopen("input.txt", "r", stdin);
    /*
    else instead of freopen you can use
    g++ filename.cpp
    ./a < input.txt
    */
    node *head = NULL;
    createLinkedList(head);
    print(head);

    return 0;
}