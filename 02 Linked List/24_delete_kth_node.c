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

void deleteNode(Node **head, int k)
{
    if (*head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    if (k == 1)
    {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    Node *temp = *head;
    for (int i = 1; i < k - 1; i++)
    {
        if (temp == NULL || temp->next == NULL)
        {
            printf("Invalid position!\n");
            return;
        }
        temp = temp->next;
    }
    Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}

int main()
{
    Node *list = NULL;
    int n, data, k;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the data %d : ", i + 1);
        scanf("%d", &data);
        insert(&list, data);
    }
    printf("The original list is: ");
    printList(list);
    printf("Enter the position of the node to delete: ");
    scanf("%d", &k);
    deleteNode(&list, k);
    printf("The updated list is: ");
    printList(list);
    return 0;
}