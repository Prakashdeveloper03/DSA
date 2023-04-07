#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
} *front = NULL, *rear = NULL;

int stack[20], top = -1;

void insert_Rear(int item)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = item;
    temp->link = NULL;
    if (front == NULL)
        front = temp;
    else
        rear->link = temp;
    rear = temp;
}

void insert_Front(int item)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = item;
    temp->link = NULL;
    if (rear == NULL)
        rear = temp;
    else
        temp->link = front;
    front = temp;
}

int del_Front()
{
    struct node *temp;
    int item;
    temp = front;
    item = temp->info;
    front = front->link;
    free(temp);
    return item;
}

int del_Rear()
{
    struct node *pre, *ptr, *temp;
    int item;
    if (front == rear)
    {
        item = front->info;
        free(front);
        front = NULL;
        rear = NULL;
        return item;
    }
    ptr = front;
    while (ptr->link != rear)
    {
        ptr = ptr->link;
    }
    item = rear->info;
    temp = rear;
    rear = ptr;
    ptr->link = NULL;
    free(temp);
    return item;
}

int isEmpty()
{
    if (front == NULL)
        return 1;
    else
        return 0;
}

int peek()
{
    if (isEmpty())
    {
        printf("Queue is Empty:");
        return 0;
    }
    return front->info;
}

void display()
{
    struct node *ptr;
    ptr = front;
    if (isEmpty())
    {
        printf("Queue is Empty:");
        return;
    }
    while (ptr != NULL)
    {
        printf("%d ", ptr->info);
        ptr = ptr->link;
    }
    printf("\n");
}

int main()
{
    int option, item;
    while (1)
    {
        printf("\n1. Insert at Front");
        printf("\n2. Insert at Rear");
        printf("\n3. Delete from Rear");
        printf("\n4. Delete from front");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\nEnter your option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter the element for insertion:");
            scanf("%d", &item);
            insert_Front(item);
            break;
        case 2:
            printf("Enter the element for insertion:");
            scanf("%d", &item);
            insert_Rear(item);
            break;
        case 3:
            printf("Deleted Item at the REAR of queue %d\n", del_Rear());
            break;
        case 4:
            printf("Deleted Item at the FRONT of queue %d\n", del_Front());
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        }
    }
}