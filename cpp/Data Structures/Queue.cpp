#include<stdio.h>
#include<stdlib.h>
#define NUL nullptr

struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;

struct node* create_node(int x)
{
    struct node* temp = (struct node*) malloc(1*sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

void print_queue(struct node *head)
{
    struct node *ptr = head;
    while (ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct node* enqueue(struct node *head, int x)
{
    if (head==NULL)
        return create_node(x);
    else
    {
        head->next = enqueue(head->next, x);
        return head;
    }
    
}

struct node* dequeue(struct node *head)
{
    struct node* del_node = head;
    head = head->next;
    free(del_node);
    return head;
}

int main()
{
    int n,x;
    scanf("%d",&n);
    //Enqueueing
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        head = enqueue(head, x);
        print_queue(head);
    }

    printf("\n");

    //Dequeueing
    for(int i=0;i<n;i++)
    {
        head = dequeue(head);
        print_queue(head);
    }

    return 0;
}