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

Node *reverseList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *rest = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
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
    printf("The original list is: ");
    list = reverseList(list);
    printList(list);
    list = reverseList(list);
    printf("The reversed list is: ");
    printList(list);
    return 0;
}