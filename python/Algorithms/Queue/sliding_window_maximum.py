# Python program to find the maximum for
# each and every contiguous subarray of
# size k

from collections import deque

# A Deque (Double ended queue) based
# method for printing maximum element
# of all subarrays of size k


def printMax(arr, n, k):
    """ Create a Double Ended Queue, Qi that 
    will store indexes of array elements. 
    The queue will store indexes of useful 
    elements in every window and it will 
    maintain decreasing order of values from 
    front to rear in Qi, i.e., arr[Qi.front[]] 
    to arr[Qi.rear()] are sorted in decreasing 
    order"""
    Qi = deque()

    # Process first k (or first window)
    # elements of array
    for i in range(k):

        # For every element, the previous
        # smaller elements are useless
        # so remove them from Qi
        # print("Q", Qi[-1])
        while Qi and arr[i] >= arr[Qi[-1]]:
            (Qi.pop())

        # Add new element at rear of queue
        Qi.append(i)
        # print("Q", Qi)
        # Process rest of the elements, i.e.
        # from arr[k] to arr[n-1]
    for i in range(k, n):

        # The element at the front of the
        # queue is the largest element of
        # previous window, so print it
        print(str(arr[Qi[0]]) + " ", end="")

        # Remove the elements which are
        # out of this window
        while Qi and Qi[0] <= i-k:

            # remove from front of deque
            Qi.popleft()
        # Remove all elements smaller than
        # the currently being added element
        # (Remove useless elements)
        while Qi and arr[i] >= arr[Qi[-1]]:
            Qi.pop()

        # Add current element at the rear of Qi
        Qi.append(i)

        # Print the maximum element of last window
    print(str(arr[Qi[0]]))


# Driver programm to test above fumctions
if __name__ == "__main__":
    arr = [12, 1, 78, 90, 57, 89, 56]
    k = 3
    printMax(arr, len(arr), k)
# Time Complexity: O(n).
# It seems more than O(n) at first look. It can be observed that every element of array is added and removed at most once. So there are total 2n operations.
# Auxiliary Space: O(k).
# Elements stored in the dequeue take O(k) space.
