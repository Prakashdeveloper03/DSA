#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void append(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    new_node->prev = last;
}

void move_middle_node_to_top(struct Node **head_ref)
{
    if (*head_ref == NULL || (*head_ref)->next == NULL)
        return;
    struct Node *slow_ptr = *head_ref, *fast_ptr = *head_ref;
    while (fast_ptr != NULL && fast_ptr->next != NULL)
    {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }

    if (fast_ptr == NULL)
        slow_ptr = slow_ptr->prev;

    if (slow_ptr == *head_ref)
        return;

    slow_ptr->prev->next = slow_ptr->next;
    if (slow_ptr->next != NULL)
        slow_ptr->next->prev = slow_ptr->prev;

    slow_ptr->prev = NULL;
    slow_ptr->next = *head_ref;
    (*head_ref)->prev = slow_ptr;
    *head_ref = slow_ptr;
}

void print_list(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main()
{
    struct Node *head = NULL;
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the data %d : ", i + 1);
        scanf("%d", &data);
        append(&head, data);
    }
    printf("Original list:\n");
    print_list(head);
    move_middle_node_to_top(&head);
    printf("\nModified list:\n");
    print_list(head);
    return 0;
}
