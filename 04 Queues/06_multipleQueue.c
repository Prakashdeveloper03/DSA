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

int main(int argc, const char *argv[])
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
    printf("\nEnter the no of elements to insert in queue 2 : ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
    {
        printf("Enter the value : ");
        scanf("%d", &value);
        enqueue(q2, value);
    }
    return 0;
}