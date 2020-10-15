/*
    MIDPOINT RUNNER TECHNIQUE
    
    Aim : To find midPoint of the linkedlist
    thus consider tow pointer 
    slow pointer moving at speed x
    fast pointer moving at speed 2x

    thus when fast is at the end of the list 
    slow pointer would be at middle of linkedlist

    if the linkedlist has even no of nodes then start slow from head
    and fast from head->next (one node ahead)
*/

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
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

node *midpoint(node *head)
{
    // this function returns slow pointer
    if (head == NULL || head->next == NULL)
    {
        return head; // edge case
    }

    node *slow = head;
    node *fast = head->next;

    while (fast != NULL and fast->next != NULL)
    {
        fast = (fast->next)->next;
        slow = slow->next;
    }
    return slow;
}

void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " <-- ";
        head = head->next;
    }
    cout << endl;
    return;
}

int main()
{
    node *head = NULL;

    for (int i = 0; i <= 10; i++)
    {
        insertAtHead(head, i);
    }

    print(head);
    node *mid = midpoint(head);

    cout << mid->data;

    return 0;
}