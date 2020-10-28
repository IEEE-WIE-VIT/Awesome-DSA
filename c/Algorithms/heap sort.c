#include<stdio.h>
void main()
{
    char a[10];
    int n,i;
    printf("enter the string:");
    scanf("%s",&a);
    n=strlen(a);
    heapsort(a, n);
    printf("sorted string\n");
    for (i=0; i<n;i++)
    printf("%c\n",a[i]);
}

void heapify(char a[], int n, int i)
{
    char temp;
    int root = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left<n && a[left]>a[root])
        root=left;

    if (right<n&& a[right] > a[root])
        root=right;

    if(root!=i)
        {
            temp = a[i];
            a[i]= a[root];
            a[root]=temp;
            heapify(a, n, root);
        }
}

void heapsort(char a[], int n)
{
    int i;
    char temp;
    for (i=n/2-1;i>=0;i--)
        heapify(a,n,i);
    for (i=n-1; i>=0; i--)
    {
        temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        heapify(a,i,0);
    }
}
