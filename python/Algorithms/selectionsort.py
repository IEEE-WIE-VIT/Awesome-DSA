def selectionsort(a): #a is the list of elements
    n=len(a)
    for i in range(0,n):
        min=i
        for j in range(i+1,n):
            if a[j]<a[min]:#overhere we are finding the minimum element amongst the elements a[i+1].....a[n-1]
                min=j
        a[i],a[min]=a[min],a[i]#we are swapping the element at i th index with the minimum element in the list after ith index
    return a
    #[2,3,5,4,1] lets say this is the list to be sorted
    #now starting with 2 ie 0th index elements
    #the minimum of the list[3,5,4,1] is 1
    #so swap it with 2 ie now the list is [1,3,5,4,2]
    #for the next iteration  3 and 2 will be swapped
    #for the ith iteration a[0,...i-1] will be sorted
llist=[int(x) for x in input().split()]
print(selectionsort(llist))#it prints the sorted list
