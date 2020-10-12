#include<iostream>
#include<string.h>

using namespace std;

int factorial(int);
void push_stack(char*[]);
void swap(char[],int,int);
void permute(char[],int,int);
void display_stack(char[]);

char stack[1000];
int top=-1,size;

int main()
{
    char str[100];
    cout<<"\n ENTER THE STRING : ";
    cin>>str;
    int n=strlen(str);
    size=int(factorial(n));
    permute(str,0,n);
    display_stack(stack);
}


int factorial(int n)
{
    if(n==1 || n==0)
        return 1;
    else
        return(factorial(n-1)*n);
}
void push_stack(char *wd)
{
    if(top==size)
        cout<<"\n STACK OVERERFLOW ";
    else
    {
        top++;
        stack[top]=*wd;
    }
}
void swap(char wd[],int l,int r)
{
    char temp;
    temp=wd[l];
    wd[l]=wd[r];
    wd[r]=temp;
}
void permute(char wd[],int lower,int upper)
 {
    if (lower == upper-1)
        //cout<<wd<<endl;
        push_stack(wd);
    else
    {
        for (int i = lower; i <= upper; i++)
        {
            swap(wd[lower], wd[i]);
            permute(wd, lower+1, upper);
            swap(wd[lower], wd[i]);
        }
    }
 }

 void display_stack(int dstack[])
{
    if(top==-1)
    {
        printf("\n THE STACK IS EMPTY");

    }
    else
    {
     printf("\n THE STACK IS \n");
     for(int i=top; i>=0; i--)
        printf("\n%d",dstack[i]);
    }

}
