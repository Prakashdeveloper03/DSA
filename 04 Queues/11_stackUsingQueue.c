#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack
{
    int top;
    int capacity;
    int *array;
};

struct Stack *createStack(int capacity)
{
    struct Stack *S = malloc(sizeof(struct Stack));
    if (!S)
        return NULL;
    S->capacity = capacity;
    S->top = -1;
    S->array = malloc(S->capacity * sizeof(int));
    if (!S->array)
        return NULL;
    return S;
}

int isEmpty(struct Stack *S)
{
    return (S->top == -1);
}

int size(struct Stack *S)
{
    return (S->top + 1);
}

int isFull(struct Stack *S)
{
    return (S->top == S->capacity - 1);
}

void doubleStack(struct Stack *S)
{
    S->capacity *= 2;
    S->array = realloc(S->array, S->capacity * sizeof(int));
}

void push(struct Stack *S, int data)
{
    if (isFull(S))
        doubleStack(S);
    S->array[++S->top] = data;
}

int pop(struct Stack *S)
{
    if (isEmpty(S))
    {
        printf("Stack is Empty\n");
        return INT_MIN;
    }
    else
        return (S->array[S->top--]);
}

int peek(struct Stack *S)
{
    if (isEmpty(S))
    {
        printf("Stack is Empty");
        return INT_MIN;
    }
    else
        return (S->array[S->top]);
}

void deleteStack(struct Stack *S)
{
    if (S)
    {
        if (S->array)
            free(S->array);
        free(S);
    }
}

struct Queue
{
    struct Stack *S1;
    struct Stack *S2;
};

int queueSize(struct Queue *Q)
{
    return size(Q->S1);
}

struct Queue *createQueue(int capacity)
{
    struct Stack *S1 = createStack(capacity);
    struct Stack *S2 = createStack(capacity);
    struct Queue *Q = malloc(sizeof(struct Queue));
    if (!Q)
        return NULL;
    Q->S1 = S1;
    Q->S2 = S2;
    return Q;
}

void enQueue(struct Queue *Q, int data)
{
    push(Q->S1, data);
}

int deQueue(struct Queue *Q)
{
    if (!isEmpty(Q->S2))
        return pop(Q->S2);
    else
    {
        while (!isEmpty(Q->S1))
            push(Q->S2, pop(Q->S1));
        return pop(Q->S2);
    }
}

void deleteQueue(struct Queue *Q)
{
    if (Q)
    {
        if (Q->S1)
            free(Q->S1);
        if (Q->S2)
            free(Q->S2);
        free(Q);
    }
}

int main()
{
    struct Queue *Q;
    Q = createQueue(6);
    int n, value;
    printf("Enter the number of elements to be inserted : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value : ");
        scanf("%d", &value);
        enQueue(Q, value);
    }
    printf("\nEnter the number of elements to be deleted : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Dequeued element : %d\n", deQueue(Q));
    }
    deleteQueue(Q);
    return 0;
}