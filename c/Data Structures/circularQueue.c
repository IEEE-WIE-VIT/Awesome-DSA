#include<stdio.h>
#include<stdlib.h>

typedef struct queue
{
    int rear, front, size;
    unsigned int capacity;
    int *array;
} Queue;

Queue *newQueue(const unsigned int capacity)
{
    Queue *pqueue = (Queue *) calloc(1,sizeof(Queue));
    pqueue->rear = capacity-1;
    pqueue->front = 0;
    pqueue->size = 0;
    pqueue->capacity = capacity;
    pqueue->array = (int *)calloc(capacity,sizeof(int));
    return pqueue;
}

int isEmpty(Queue *pqueue)
{
    return pqueue->size == 0;
}

int isFull(Queue *pqueue)
{
    return pqueue->size == pqueue->capacity;
}

int enqueue(Queue *pqueue, int data)
{
    if(isFull(pqueue))
    {
        return -1;
    }
    pqueue->rear = (pqueue->rear +1) % pqueue->capacity;
    pqueue->array[pqueue->rear] = data;
    (pqueue->size)++;
    return 0;

}

int deueue(Queue *pqueue)
{
    if(isEmpty(pqueue))
    {
        return -1;
    }
    int data = pqueue->array[pqueue->front];
    pqueue->front = (pqueue->front +1)%pqueue->capacity;
    (pqueue->size)--;
    return data;

}

int peek(Queue *pqueue)
{
    if(isEmpty(pqueue))
    {
        return -1;
    }
    return pqueue->array[pqueue->front];
}

int main()
{

}
