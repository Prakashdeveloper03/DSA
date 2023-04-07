#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        newNode->next = *head;
        *head = newNode;
    }
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void findMinMax(Node *head, int *min, int *max)
{
    Node *temp = head;
    *min = INT_MAX;
    *max = INT_MIN;
    while (temp != NULL)
    {
        if (temp->data < *min)
        {
            *min = temp->data;
        }
        if (temp->data > *max)
        {
            *max = temp->data;
        }
        temp = temp->next;
    }
}

int main()
{
    Node *list = NULL;
    int n, data;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the data %d : ", i + 1);
        scanf("%d", &data);
        insert(&list, data);
    }
    printf("The linked list is: ");
    printList(list);
    int min, max;
    findMinMax(list, &min, &max);
    printf("The minimum value is: %d\n", min);
    printf("The maximum value is: %d\n", max);
    return 0;
}