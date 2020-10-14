#include<stdio.h>
#include<stdlib.h>
#define NULL nullptr

struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;

struct node* create_node(int x)
{
    struct node* temp = (struct node*) malloc(1*sizeof(struct node));
    temp->data = x;
    temp->next=NULL;
    return temp;
}

struct node* push(struct node *head, int x)
{
    if (head==NULL)
        head = create_node(x);
    else
    {
        struct node *new_node = create_node(x);
        new_node->next = head;
        head = new_node;
    }
    return head;
}

struct node* pop(struct node *head)
{
    struct node* del_node = head;
    head = head->next;
    free(del_node);
    return head;
}

void print_stack(struct node *head)
{
    struct node *ptr = head;
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return;
}

int main()
{
    int n,x;
    scanf("%d",&n);
    // PUSHING
    for (int i=0;i<n;i++)
    {
        scanf("%d",&x);
        head = push(head, x);
        print_stack(head);
    }

    printf("\n");

    //POPING
    for (int i=0;i<n;i++)
    {
        head = pop(head);
        print_stack(head);
    }

    return 0;
}