#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int value)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = value;
    ptr->next = NULL;
    if ((front == NULL) && (rear == NULL))
        front = rear = ptr;
    else
    {
        rear->next = ptr;
        rear = ptr;
    }
    printf("Node is Inserted\n\n");
}

int dequeue()
{
    if (front == NULL)
    {
        printf("\nUnderflow\n\n");
        return -1;
    }
    else
    {
        struct node *temp = front;
        int temp_data = front->data;
        front = front->next;
        free(temp);
        return temp_data;
    }
}

void display()
{
    struct node *temp;
    if ((front == NULL) && (rear == NULL))
        printf("\nQueue is Empty\n\n");
    else
    {
        printf("The queue is \n");
        temp = front;
        while (temp)
        {
            printf("%d--->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n\n");
    }
}

int main()
{
    int choice, value;
    printf("\nImplementation of Queue using Linked List\n");
    while (1)
    {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
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
            printf("Deleted element is :%d\n\n", dequeue());
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nInvalid Choice\n\n");
        }
    }
    return 0;
}
