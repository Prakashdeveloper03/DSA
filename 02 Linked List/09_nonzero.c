#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int data;
    struct ListNode *next;
} * head;

void initialize()
{
    head = NULL;
}

void insert(int data)
{
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void printNonZero(struct ListNode *ListNodePtr)
{
    while (ListNodePtr != NULL)
    {
        if (ListNodePtr->data > 0)
        {
            printf("%d ", ListNodePtr->data);
        }
        ListNodePtr = ListNodePtr->next;
    }
}

void printLinkedList(struct ListNode *ListNodePtr)
{
    while (ListNodePtr != NULL)
    {
        printf("%d", ListNodePtr->data);
        ListNodePtr = ListNodePtr->next;
        if (ListNodePtr != NULL)
            printf(" ");
    }
}

struct ListNode *reverseLinkedList(struct ListNode *head)
{
    struct ListNode *previous, *current, *next;
    previous = NULL;
    current = head;

    while (current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    return previous;
}

int main()
{
    initialize();
    int n, val;
    printf("Enter the no of elements : ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("Enter the number %d : ", i);
        scanf("%d", &val);
        insert(val);
    }
    head = reverseLinkedList(head);
    printf("\nOriginal Linked List\n");
    printLinkedList(head);
    printf("\n\nLinked List without non-zero elements : \n");
    printNonZero(head);
    printf("\n");
    return 0;
}