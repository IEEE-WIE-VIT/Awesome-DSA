#include<iostream>
#include<stdlib.h>
#include<conio.h>


using namespace std;
class Queue {
 int Q[100];
 int item,N,front,rear;
 public:
 Queue()

{
 front=rear=-1;
 N=100;

}
 void Qinsert()

{
 cout<<"\nEnter the element to be inserted:";
 cin>>item;
 if(rear==-1)

{
 front=rear=0;
 Q[0]=item;

}
 else if(rear==N-1)
 cout<<"\nQueue Full";
 else

{
 rear=rear+1;
 Q[rear]=item;

}

}

 void Qdelete()
 {if(front == -1)
 cout<<"Queue Empty";
 else
 { item = Q[front];
 if(front==rear)
front=rear=-1;
 else
front=front+1;
 }
 }
 void Qdisplay()
 {
 if(front==-1)
 cout<<"\nQueue Empty";
 else
 {
 cout<<"\nQueue is\n";
 for(int i=front;i<=rear;++i)
 cout<<Q[i]<<" ";
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
switch(ch)
{
 case 1: Obj.Qinsert();getch();goto ll;
 			
 case 2: Obj.Qdelete();getch();goto ll;

 case 3: Obj.Qdisplay();getch();goto ll;

 case 4: exit(0);
}


}
