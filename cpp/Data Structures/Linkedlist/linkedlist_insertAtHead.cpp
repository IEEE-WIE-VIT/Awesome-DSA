#include <iostream>
using namespace std;

class node
{

public:
    int data;
    node *next; // why node *next and not int *next?
    // because we want to store the address of a node datatype and not just int
    /*
    int a = 5;
    int *ptr= &a; //so we can only reference of a pointer of same data type to another variable 
    thus *next is a pointer which points to next memory block node 
    */

    // parameterized constructor
    // the value which is passed through the parameter would be stored in the variable 'data' and 'next' would be poiting to null
    node(int d)
    {
        data = d;
        next = NULL;
    }
};

// here we are using node *&head because we need a pointer which can point to node
void insertAtHead(node *&head, int data)
{
    //thus we are creating it of data type node and further we add & so that we can easily change the it (pass by reference)
    //if we are only using node* head we are basically creating a copy of the variable (pass by value and the changes done to head is not reflected) thus passing by reference so that we can change the actual value of the variable i.e we need to change our head pointer

    // check if any node is present or not i.e if head == NULL
    if (head == NULL)
    {
        // if no node is present

        /*
        you can do this way but remember at the end of function the var n created here is a static one. NOTE the memory of node exists till the program terminates but the static variables like n are deleted instantly 
        why to create a new var when we have head simply use it
        although you can use the method below
        node *n = new node(data);
        head = n;
        */

        head = new node(data);
        return;
    }

    node *n = new node(data);
    // if you dont want to pass data as a param use this n->data = data;
    n->next = head; //why n->next ? what is '->' ? what is obj of class node
    head = n;
    /*  taking an example :
        class ABC{
            public: int data;
        }obj;
            
            //so we can refer the data by using the object thus here object is obj 
            //we can clearly see *n is the object of class node
            //thus we can access the data by obj.data vin class ABC
            //thus rewriting it as (*n).data = 5; for class node
            //so we can easily rewrite it as n->data = 5;
        */
    return;
}

void print(node *head)
{
    // here as you can see that we are passing by value since we dont want our original head to be changed
    // so instead of original head a copy of original head is created and then we iterate
    // later at the end the copy of head gets deleted

    while (head != NULL)
    {
        // arrow denotes   head <- tail
        cout << head->data << "<--";
        head = head->next;
    }
}

int main()
{
    // creating a head pointer
    node *head = NULL;

    for (int i = 0; i <= 10; i++)
    {
        insertAtHead(head, i);
    }

    // printing the linkedlist
    print(head);
}