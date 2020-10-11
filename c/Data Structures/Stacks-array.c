#include <stdio.h>
#include <conio.h>


//STACKS of size 10 USING ARRAYS 
int main()
{
	int top=-1;
	int stack[10];
		int push()
		{
			if(top<10)
			{
				int x;
				printf("\nEnter the data: ");
				scanf("%d",&x);
				++top;
				stack[top]=x;
			}
			else
			{
				printf("Stack overflow");
			}
		}
		
		int pop()
		{
			if(top!=-1)
			{
				printf("%d",stack[top]);
				top--;				
			}
			else{
				printf("Stack underflow");
			}
		}
		
		int display()
		{
			if(top!=-1)
			{
				printf("this is the top\n");
				int i;
				for(i=top;i>=0;i--)
				{
					printf("%d\n",stack[i]);
				}
			}
		}
	
	L:
	printf("enter 1 for push\n");
	printf("enter 2 for pop\n");
	printf("enter 3 for display\n");
	printf("enter 4 for exit\n");
	printf("enter choice: ");
	
	int m;
	scanf("%d",&m);
	
	switch(m)
	{
		case 1:
			push();
			goto L;
		case 2:
			pop();
			goto L;
		case 3:
			display();
			goto L;
		case 4:
			exit(1);
	}
	
	return 0;
}


