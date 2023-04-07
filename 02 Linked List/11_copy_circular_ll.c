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
        newNode->next = *head;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void printList(Node *head)
{
    Node *temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

Node *copyList(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *newHead = createNode(head->data);
    Node *temp1 = head->next;
    Node *temp2 = newHead;
    while (temp1 != head)
    {
        Node *newNode = createNode(temp1->data);
        temp2->next = newNode;
        temp2 = temp2->next;
        temp1 = temp1->next;
    }
    temp2->next = newHead;
    return newHead;
}

int main()
{
    Node *head = NULL;
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the data %d : ", i + 1);
        scanf("%d", &data);
        insert(&head, data);
    }
    printf("Original list: ");
    printList(head);
    Node *copy = copyList(head);
    printf("Copy of the list: ");
    printList(copy);
    return 0;
}