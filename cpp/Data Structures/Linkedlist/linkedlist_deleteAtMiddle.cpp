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
        // no node is present
        head = new node(data);
        return;
    }

    // else head is pointing to a node
    node *n = new node(data);
    n->next = head;
    head = n;
}

void insertAtTail(node *&head, int data)
{
    if (head == NULL)
    {
        // no node is present thus insertAtHead
        insertAtHead(head, data);
        return;
    }

    // if the linked list already exists then iterate over the linkedlist untill you reach the end
    node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    // now we are at the end of the linkedlist
    // insert a new node
    tail->next = new node(data);
    return;
}

int length(node *head)
{
    int count(0);
    while (head != NULL)
    {
        head = head->next;
        count++;
    }
    return count;
}

void insertAtMiddle(node *&head, int data, int pos)
{
    if (pos == 0 || head == NULL)
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
        // insert a new node at pos
        // jump to the pos
        int jumps = 1;
        node *temp = head; // since we dont want to change head ptr
        while (jumps <= pos - 1)
        {
            temp = temp->next;
            jumps++;
        }
        // we have now reached pos
        // create a node and insert it
        node *n = new node(data);
        n->next = temp->next;
        temp->next = n;
    }
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

void deleteAtHead(node *&head)
{
    if (head == NULL)
    {
        return; // delete nothing
    }
    node *n = head->next;
    delete head;
    head = n;
    return;
}

void deleteAtTail(node *&head)
{
    node *tail = head;
    while ((tail->next)->next != NULL)
    {
        tail = tail->next;
    }
    delete tail->next;
    tail->next = NULL;
    return;
}

void deleteAtMiddle(node *&head, int pos)
{
    if (head == NULL)
    {
        // delete nothing
        return;
    }
    else if (pos == 0)
    {
        // if pos = 0 then deleteAtHead
        deleteAtHead(head);
    }
    if (pos >= length(head))
    {
        deleteAtTail(head);
        return;
    }
    else
    {
        node *tail = head;
        // reach the pos and delete that pos
        int jumps = 1;
        // we have to take pos -1 jumps

        while (jumps <= pos - 1)
        {
            tail = tail->next;
            jumps++;
        }

        // we have reached the previous node;
        // so we have to del next node i.e tail->next;
        node *forward = tail->next;
        tail->next = forward->next;
        delete forward;
    }
    return;
}

int main()
{
    // creating a head pointer
    node *head = NULL;

    insertAtMiddle(head, 1, 0);
    print(head);

    insertAtMiddle(head, 0, 0);
    print(head);

    insertAtMiddle(head, 2, 2);
    print(head);

    deleteAtMiddle(head, 1);
    print(head);

    insertAtTail(head, 3);
    print(head);

    deleteAtTail(head);
    print(head);

    deleteAtHead(head);
    print(head);

    insertAtHead(head, 0);
    print(head);

    insertAtMiddle(head, 1, 1);
    print(head);

    return 0;
}