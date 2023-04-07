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
        (*head)->prev = newNode;
        (*head)->next = newNode;
    }
    else
    {
        Node *tail = (*head)->prev;
        newNode->prev = tail;
        newNode->next = *head;
        tail->next = newNode;
        (*head)->prev = newNode;
    }
}

void printList(Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    Node *temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void swap(Node *a, Node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void bubbleSort(Node *head)
{
    int swapped = 0;
    Node *temp1, *temp2 = NULL;
    if (head == NULL)
    {
        return;
    }
    do
    {
        swapped = 0;
        temp1 = head;
        while (temp1->next != temp2)
        {
            if (temp1->data > temp1->next->data)
            {
                swap(temp1, temp1->next);
                swapped = 1;
            }
            temp1 = temp1->next;
        }
        temp2 = temp1;
    } while (swapped);
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
    bubbleSort(head);
    printf("Sorted list: ");
    printList(head);
    return 0;
}