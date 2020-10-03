def linearsearch(llist,key):#this algorithm takes O(n) time complexity
    for i in range(len(llist)):
        if llist[i]==key:
            return i+1 #return the position of the key in the list
    return -1 #return -1 if key not found

llist=[int(x) for x in input().split()]
key=int(input()) #key is the element to be searched
position=linearsearch(llist,key)
if position>0:
    print(key,"found at position",position)
else:
    print("Not Found!")
#this is an iterative approach
