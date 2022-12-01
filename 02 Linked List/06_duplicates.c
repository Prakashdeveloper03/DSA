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

void removeDuplicates(struct ListNode *head)
{
    struct ListNode *ptr1, *ptr2, *dup;
    ptr1 = head;
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;
        while (ptr2->next != NULL)
        {
            if (ptr1->data == ptr2->next->data)
            {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
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
    printf("\nLinked List with duplicates\n");
    printLinkedList(head);
    printf("\n\nLinked List without duplicates\n");
    removeDuplicates(head);
    printLinkedList(head);
    printf("\n");
    return 0;
}