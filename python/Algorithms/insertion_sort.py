def insertionSortRecursive(array,n): 
    # base case 
    if n<=1: 
        return
      
    # Sort first n-1 elements 
    insertionSortRecursive(array,n-1) 
    last = array[n-1] 
    j = n-2
      
      # Move elements of arr[0..i-1], that are 
      # greater than key, to one position ahead 
      # of their current position  
    while (j>=0 and array[j]>last): 
        array[j+1] = array[j] 
        j = j-1
  
    array[j+1]=last 
      
# A utility function to print an array of size n 
def printarr(array,n): 
    for i in range(n): 
        print array[i], 
  
array = [12,11,13,5,6] 
n = len(array) 
insertionSortRecursive(array, n) 
printarr(array, n) 
