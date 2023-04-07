#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
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
        Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
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

void deleteFirstAndAddLast(Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    Node *first = *head, *last = *head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    *head = first->next;
    if (first->next != NULL)
    {
        first->next->prev = NULL;
    }
    first->next = NULL;
    first->prev = last;
    last->next = first;
}

int main()
{
    Node *list = NULL;
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the data %d : ", i + 1);
        scanf("%d", &data);
        insert(&list, data);
    }
    printf("Original list: ");
    printList(list);
    deleteFirstAndAddLast(&list);
    printf("List after deleting first and adding last: ");
    printList(list);
    return 0;
}