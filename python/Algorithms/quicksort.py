
# Function that swaps places for to indexes (x, y) of the given array (arr)
def swap(arr, x, y): 
    tmp = arr[x]
    arr[x] = arr[y]
    arr[y] = tmp
    return arr

def partition(arr, first, last):
    pivot = arr[last]
    index = first
    i = first


    while i < last:
        if arr[i] <= pivot: # Swap if current element is smaller to the pivot
            arr = swap(arr, i, index)
            index += 1

        i += 1
    arr = swap(arr, index, last)
    return index

def quickSort(arr, first, last):
    if first < last:
        pivot = partition(arr, first, last)

        # Implement quicksort on both sides of pivot
        quickSort(arr, first, pivot-1)
        quickSort(arr, pivot+1, last)
    return arr

# Test array
array = [1, 10, 2, 4, 1, 9, 6, 7, 10, 4, 11, 3]

print("Unsorted test array: ", array)
quickSort(array, 0, len(array)-1)
print("Sorted test array: ", array)