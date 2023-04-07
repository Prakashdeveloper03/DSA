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

Node *mergeLists(Node *list1, Node *list2)
{
    if (list1 == NULL)
    {
        return list2;
    }
    if (list2 == NULL)
    {
        return list1;
    }
    Node *mergedList = NULL;
    if (list1->data <= list2->data)
    {
        mergedList = list1;
        mergedList->next = mergeLists(list1->next, list2);
    }
    else
    {
        mergedList = list2;
        mergedList->next = mergeLists(list1, list2->next);
    }
    return mergedList;
}

int main()
{
    Node *list1 = NULL;
    Node *list2 = NULL;
    int n1, n2, data;
    printf("Enter the number of nodes for list 1: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
    {
        printf("Enter the data %d : ", i + 1);
        scanf("%d", &data);
        insert(&list1, data);
    }
    printf("\nEnter the number of nodes for list 2: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
    {
        printf("Enter the data %d : ", i + 1);
        scanf("%d", &data);
        insert(&list2, data);
    }
    printf("\nList 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);
    Node *mergedList = mergeLists(list1, list2);
    printf("\nMerged list: ");
    printList(mergedList);
    return 0;
}