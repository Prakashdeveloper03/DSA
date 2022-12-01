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

int isSorted(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return 1;
    return ((head->data > head->next->data) && isSorted(head->next));
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
    int res = isSorted(head);
    if (res)
        printf("\nLinked list is sorted in ascending order\n", res);
    else
        printf("\nLinked list is not sorted in ascending order\n", res);
    return 0;
}