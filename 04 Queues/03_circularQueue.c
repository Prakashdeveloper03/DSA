#include <stdio.h>
#include <stdlib.h>
#define SIZE 50
int items[SIZE];
int front = -1, rear = -1;

int isFull()
{
    if ((front == rear + 1) || (front == 0 && rear == SIZE - 1))
        return 1;
    return 0;
}

int isEmpty()
{
    if (front == -1)
        return 1;
    return 0;
}

void enqueue(int element)
{
    if (isFull())
        printf("\nQueue is full\n");
    else
    {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        printf("\nInserted -> %d", element);
    }
}

int dequeue()
{
    int element;
    if (isEmpty())
    {
        printf("\nQueue is empty\n");
        return (-1);
    }
    else
    {
        element = items[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
            front = (front + 1) % SIZE;
        printf("\nDeleted element -> %d \n", element);
        return (element);
    }
}

void display()
{
    int i;
    if (isEmpty())
        printf(" \nEmpty Queue\n");
    else
    {
        printf("\nItems -> ");
        for (i = front; i != rear; i = (i + 1) % SIZE)
        {
            printf("%d ", items[i]);
        }
        printf("%d ", items[i]);
    }
}

int main()
{
    int choice, value;
    printf("\nImplementation of Circular Queue using arrays");
    while (1)
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nInvalid Choice\n");
        }
    }
    return 0;
}
