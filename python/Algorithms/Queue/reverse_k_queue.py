# Python3 program to reverse first k
# elements of a queue.
from queue import Queue

# Function to reverse the first K
# elements of the Queue


def reverseQueueFirstKElements(k, Queue):
    if (Queue.empty() == True or
            k > Queue.qsize()):
        return
    if (k <= 0):
        return

    Stack = []

    # put the first K elements
    # into a Stack
    for _ in range(k):
        Stack.append(Queue.queue[0])
        Queue.get()

    # Enqueue the contents of stack
    # at the back of the queue
    while (len(Stack) != 0):
        Queue.put(Stack[-1])
        Stack.pop()

    # Remove the remaining elements and
    # enqueue them at the end of the Queue
    for _ in range(Queue.qsize() - k):
        Queue.put(Queue.queue[0])
        Queue.get()

# Utility Function to print the Queue


def Print(Queue):
    while (not Queue.empty()):
        print(Queue.queue[0], end=" ")
        Queue.get()


# Driver code
if __name__ == '__main__':
    Queue = Queue()
    Queue.put(10)
    Queue.put(20)
    Queue.put(30)
    Queue.put(40)
    Queue.put(50)
    Queue.put(60)
    Queue.put(70)
    Queue.put(80)
    Queue.put(90)
    Queue.put(100)

    k = 5
    reverseQueueFirstKElements(k, Queue)
    Print(Queue)
