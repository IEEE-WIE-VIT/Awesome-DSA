
#include <stdio.h>

void quicksort(int [],int,int);
int split(int [],int,int);
int main()
{
    int a[]={11,2,9,13,57,25,17,1,90,3};
    int i;
    quicksort(a,0,9);
    for (i=0; i<10; i++)printf("%d\t",a[i]);
    return 0;
}

void quicksort(int a[],int lower,int upper){
    int i;
    if (upper>lower){
        i=split(a,lower,upper);
        quicksort(a,lower,i-1);
        quicksort(a,i+1,upper);
    }
}

int split(int a[], int lower, int upper){
    int p,q,num,temp;
    p=lower+1;
    q=upper;
    num=a[lower];
    while (q>=p){
        while (a[p]<num)p++;
        while (a[q]>num)q--;
        if (q>p){
            temp=a[p];
            a[p]=a[q];
            a[q]=temp;
        }
    }
    temp=a[lower];
    a[lower]=a[q];
    a[q]=temp;
    
    return q;
}