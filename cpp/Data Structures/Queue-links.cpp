#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;
struct node {
int info;
node *next;
};
class Queue {
 node *front,*rear,*newptr;
 public:
 Queue()

{
 front=rear=NULL;

}
 void Qinsert()

{
 newptr=new node;
 cout<<"\nEnter the element to be inserted:";
 cin>>newptr->info;
 newptr->next=NULL;
 if(rear==NULL)

{
 front=rear=newptr;

}
 else

{
 rear->next=newptr;
 rear=newptr;

}

}

 void Qdelete()

{
 if(front == NULL)
 cout<<"Queue Empty";
 else

{
 newptr = front;
 if(front==rear)
front=rear=NULL;
 else
front=front->next;
 delete newptr;

}

}
 void Qdisplay()

{
 if(front==NULL)
 cout<<"\nQueue Empty";
 else

{
 newptr=front;
 cout<<"\nQueue is\n";
 while(newptr!=NULL)

{
 cout<<newptr->info<<"->";
 newptr=newptr->next;

}

}

}
 ~Queue()

{
 newptr=front;
 while(newptr!=NULL)

{
 front=front->next;
 delete newptr;

}

}
};
int main() 
{ 
Queue Obj;
ll:
cout<<"\n1.Insert";
cout<<"\n2.Delete";
cout<<"\n3.Display";
cout<<"\n4.Exit";
int ch;
cin>>ch;
switch(ch) {
 case 1: Obj.Qinsert();
 break;

 case 2: Obj.Qdelete();
 break;
 case 3: Obj.Qdisplay();
 break;
 case 4: exit(0);
}
getch();
goto ll;
}