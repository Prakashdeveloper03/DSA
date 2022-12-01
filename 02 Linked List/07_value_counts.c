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

int count(struct ListNode *head, int search_for)
{
    struct ListNode *current = head;
    int count = 0;
    while (current != NULL)
    {
        if (current->data == search_for)
            count++;
        current = current->next;
    }
    return count;
}

int main()
{
    struct ListNode *middle;
    head = NULL;
    int n, val, searchfor;
    printf("Enter the no of elements : ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("Enter the number %d : ", i);
        scanf("%d", &val);
        insert(val);
    }
    head = reverseLinkedList(head);
    printf("Enter the value to counted : ");
    scanf("%d", &searchfor);
    printf("\nOriginal Linked List\n");
    printLinkedList(head);
    printf("\n\nThe total number of occurrences of %d is %d\n", searchfor, count(head, searchfor));
    return 0;
}