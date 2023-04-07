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
        Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
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

Node *createAlternateList(Node *head)
{
    Node *newHead = NULL, *temp = head, *prev = NULL;
    int count = 0;
    while (temp != NULL)
    {
        if (count % 2 == 0)
        {
            Node *newNode = createNode(temp->data);
            if (newHead == NULL)
            {
                newHead = newNode;
            }
            else
            {
                prev->next = newNode;
            }
            prev = newNode;
        }
        count++;
        temp = temp->next;
    }
    return newHead;
}

int main()
{
    Node *list = NULL, *altList = NULL;
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
    altList = createAlternateList(list);
    printf("Alternate list: ");
    printList(altList);
    return 0;
}