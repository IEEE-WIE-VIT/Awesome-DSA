/*
 main aim is to overload operator so that we can do cin>>head that 
takes input and generates a linkedlist and cout<<head that prints the 
linkedlist
we also have to do cascading of operators
so that we can print two linkedlist  eg cout<<head1<<head2
*/
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
}

void insertAtTail(node *&head, int data)
{
    if (head == NULL)
    {
        insertAtHead(head, data);
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

        int jumps = 1;
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
        return;
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
        return;
    }
    else if (pos == 0)
    {
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
        int jumps = 1;

        while (jumps <= pos - 1)
        {
            tail = tail->next;
            jumps++;
        }

        node *forward = tail->next;
        tail->next = forward->next;
        delete forward;
    }
    return;
}

void createLinkedList(node *&head)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        insertAtHead(head, data);
        cin >> data;
    }
    return;
}

// since we just need to print thus passing head by value
ostream &operator<<(ostream &os, node *head)
{
    print(head);
    return os;
}

istream &operator>>(istream &is, node *&head)
{
    createLinkedList(head);
    return is;
}

int main()
{

    node *head1 = NULL;
    node *head2 = NULL;
    cin >> head1 >> head2;
    cout << head1 << head2;

    return 0;
}

/*
INPUT :
5 4 3 2 1 -1
9 8 7 6 -1

OUTPUT : 
1<--2<--3<--4<--5<--
6<--7<--8<--9<--

*/