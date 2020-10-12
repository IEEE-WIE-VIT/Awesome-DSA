#include <stdio.h>
#include <math.h>
#define MAX 100
int search(int key);
int a[MAX],n;
void main()
{
   int i,key,result;
   printf("\nEnter the number of elements: ");
   scanf("%d",&n);
   printf("\nEnter the elements of array: \n");
   for(i=0;i<n;i++)
   {
         scanf("%d",&a[i]);
   }
      printf("\n\nEnter the key you want to search: ");
      scanf("%d",&key);
      result=search(key);
      if(result==-1)
      {
            printf("\nElement is not found in the array !\n");
      }
      else
      {
            printf("\nElement %d is present at position %d",key,result);
      }
}
int search(int key)
{
   int jump_step,prev=0;
   jump_step=floor(sqrt(n));

   while(a[prev]<key)
   {
       if(a[jump_step]>key || jump_step>=n)
       {
            break;
       }
       else
       {
                prev=jump_step;
                jump_step=jump_step+floor(sqrt(n));
       }
   }

   while(a[prev]<key)
   {
        prev++;
   }
   if(a[prev]==key)
   {
        return prev+1;
   }
   else
   {
        return -1;
   }
}
