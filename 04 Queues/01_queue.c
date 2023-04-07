#include <stdio.h>
#include <stdlib.h>
#define n 50
int queue[n], front = 0, rear = 0, i, j = 1, x = n;
void enqueue(int value)
{
    if (rear == x)
        printf("\nQueue is Full\n");
    else
        queue[rear++] = value;
}

void dequeue()
{
    if (front == rear)
        printf("\nQueue is empty\n");
    else
        printf("\nDeleted Element is %d\n", queue[front++]);
    x++;
}

void display()
{
    if (front == rear)
        printf("\nQueue is Empty\n");
    else
    {
        for (i = front; i < rear; i++)
        {
            printf("%d  ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int ch, value;
    printf("Queue using Array");
    printf("\n1.Insertion \n2.Deletion \n3.Display \n4.Exit");
    while (1)
    {
        printf("\nEnter the Choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the value to be inserted : ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            printf("\nQueue Elements are : ");
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
