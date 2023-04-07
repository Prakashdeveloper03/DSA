#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create_node(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

struct node *insert_node(struct node *head, int data)
{
    struct node *new_node = create_node(data);
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        new_node->next = head;
        head = new_node;
    }
    return head;
}

void print_list(struct node *head)
{
    struct node *current_node = head;
    while (current_node != NULL)
    {
        printf("%d -> ", current_node->data);
        current_node = current_node->next;
    }
    printf("NULL\n");
}

struct node *reverse_list(struct node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct node *current_node = head;
    struct node *prev_node = NULL;
    struct node *next_node = NULL;
    while (current_node != NULL)
    {
        next_node = current_node->next;
        current_node->next = prev_node;
        prev_node = current_node;
        current_node = next_node;
    }
    head = prev_node;
    return head;
}

int main()
{
    int n, i, data;
    struct node *head = NULL;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the data %d : ", i + 1);
        scanf("%d", &data);
        head = insert_node(head, data);
    }
    printf("Original Linked List: ");
    print_list(head);
    head = reverse_list(head);
    printf("Reversed Linked List: ");
    print_list(head);
    return 0;
}