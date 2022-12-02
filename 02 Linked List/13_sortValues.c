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

void sortList()
{
    struct ListNode *current = NULL, *index = NULL;
    int temp;
    if (head == NULL)
        return;
    else
    {
        for (current = head; current->next != NULL; current = current->next)
        {
            for (index = current->next; index != NULL; index = index->next)
            {
                if (current->data > index->data)
                {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
            }
        }
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
    struct ListNode *middle;
    head = NULL;
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
    printf("\n\nSorted Linked List : \n");
    sortList();
    printLinkedList(head);
    printf("\n");
    return 0;
}