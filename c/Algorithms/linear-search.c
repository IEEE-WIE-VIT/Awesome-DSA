#include <stdio.h> 

//Compares the values one by one to see of they match


//Search Function
int search(int arr[], int x, int size) 
{ 
    int i;
    for (i = 0; i < size; i++){
        if (arr[i] == x){
        printf("Element %d present at in index position %d\n",x,i);
        return 1;
        }
    }
    printf("Element %d not present in the array\n",x);
    return -1;
} 

//Main Program  
void main() 
{ 
    //Test case true
    int arr[] = {1,2,3,4,5,7,8,9,10}; 
    int x = 6;
    int size = sizeof(arr) / sizeof(arr[0]); 
    search(arr, x, size); 
    //Test case true
    int y = 1;
    search(arr, y, size); 

    
} 