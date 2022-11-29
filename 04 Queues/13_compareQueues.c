#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct qNode
{
    int value;
    struct qNode *next;
} QNODE;

typedef struct queue
{
    QNODE *front, *rear;
} QUEUE;

QUEUE *createNewQueue()
{
    QUEUE *q = (QUEUE *)malloc(sizeof(QUEUE));
    if (q == NULL)
    {
        printf("memory allocation failed!\n");
        exit(0);
    }
    else
    {
        q->front = q->rear = NULL;
        return q;
    }
}

int isEmpty(QUEUE *q)
{
    if (q->front == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int peekQueue(QUEUE *q)
{
    int dequeuedValue;
    if (isEmpty(q))
    {
        printf("QUEUE is empty\n");
        exit(0);
    }
    else
    {
        dequeuedValue = q->front->value;
        return dequeuedValue;
    }
}

void enqueue(QUEUE *q, int value)
{
    QNODE *newNode = (QNODE *)malloc(sizeof(QNODE));
    if (newNode == NULL)
    {
        printf("memory allocation failed\n");
        exit(0);
    }
    else
    {
        newNode->value = value;
        newNode->next = NULL;
        if (q->front == NULL)
        {
            q->front = q->rear = newNode;
        }
        else
        {
            q->rear->next = newNode;
            q->rear = newNode;
        }
    }
}

int dequeue(QUEUE *q)
{
    QNODE *tempNode;
    int dequeuedValue;
    if (isEmpty(q))
    {
        printf("QUEUE is empty\n");
        exit(0);
    }
    else
    {
        dequeuedValue = q->front->value;
        tempNode = q->front;
        q->front = tempNode->next;
        free(tempNode);
        if (q->front == NULL)
        {
            q->rear = NULL;
        }
        return dequeuedValue;
    }
}

int twoQueueComparison(QUEUE *q1, QUEUE *q2)
{
    QUEUE *tempQueue1 = createNewQueue();
    QUEUE *tempQueue2 = createNewQueue();
    int functionResult;
    while (!isEmpty(q1) && !isEmpty(q2))
    {
        if (peekQueue(q1) == peekQueue(q2))
        {
            enqueue(tempQueue1, dequeue(q1));
            enqueue(tempQueue2, dequeue(q2));
        }
        else
        {
            printf("two queue are not the same as inputs\n");
            functionResult = 0;
            break;
        }
    }
    if (isEmpty(q1) && isEmpty(q2))
    {
        functionResult = 1;
    }
    else
    {
        functionResult = 0;
        while (!isEmpty(q1))
        {
            enqueue(tempQueue1, dequeue(q1));
        }
        while (!isEmpty(q2))
        {
            enqueue(tempQueue2, dequeue(q2));
        }
    }
    while (!isEmpty(tempQueue1))
    {
        enqueue(q1, dequeue(tempQueue1));
    }
    while (!isEmpty(tempQueue2))
    {
        enqueue(q2, dequeue(tempQueue2));
    }
    return functionResult;
}

int main()
{
    int n1, n2, value;
    QUEUE *q1 = createNewQueue();
    QUEUE *q2 = createNewQueue();
    printf("Enter the no of elements to insert in queue 1 : ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
    {
        printf("Enter the value : ");
        scanf("%d", &value);
        enqueue(q1, value);
    }
    printf("Enter the no of elements to insert in queue 2 : ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
    {
        printf("Enter the value : ");
        scanf("%d", &value);
        enqueue(q2, value);
    }
    printf("The result of comparison is %d\n", twoQueueComparison(q1, q2));
    return 0;
}