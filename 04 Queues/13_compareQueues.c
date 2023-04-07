#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct QueueRecord queue_t;
typedef struct Node node_t;

struct Node
{
    int value;
    node_t *next;
};

struct QueueRecord
{
    node_t *front, *rear;
};

queue_t *createQueue(int capacity)
{
    queue_t *q = NULL;
    q = (queue_t *)malloc(sizeof(queue_t));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(queue_t *q, int element)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->value = element;

    if (!q->rear)
    {
        q->front = q->rear = node;
    }
    else
    {
        q->rear->next = node;
        q->rear = node;
    }

    printf("Element %d added to the queue\n", element);
}

bool isQueueSame(int size, queue_t *first_queue, queue_t *second_queue)
{
    node_t *first_node = first_queue->front, *second_node = second_queue->front;

    while (first_node && second_node)
    {
        if (first_node->value != second_node->value)
            return false;
        first_node = first_node->next;
        second_node = second_node->next;
    }

    return true;
}

int main()
{
    int size, item;
    printf("Enter the queue size : ");
    scanf("%d", &size);

    queue_t *first_queue = createQueue(size);
    queue_t *second_queue = createQueue(size);

    for (int i = 0; i < size; i++)
    {
        printf("Enter the items for first queue : ");
        scanf("%d", &item);
        enqueue(first_queue, item);
    }

    for (int i = 0; i < size; i++)
    {
        printf("Enter the items for second queue : ");
        scanf("%d", &item);
        enqueue(second_queue, item);
    }

    bool is_same = isQueueSame(size, first_queue, second_queue);
    if (is_same)
        printf("Both queue are the same\n");
    else
        printf("Both queue are not the same\n");
}
