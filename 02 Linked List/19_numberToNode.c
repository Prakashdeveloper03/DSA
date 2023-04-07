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

int main()
{
    Node *list = NULL;
    int n, num, digit;
    printf("Enter an n-digit number: ");
    scanf("%d", &num);
    n = 0;
    while (num > 0)
    {
        digit = num % 10;
        insert(&list, digit);
        num = num / 10;
        n++;
    }
    printf("The linked list is: ");
    printList(list);
    return 0;
}