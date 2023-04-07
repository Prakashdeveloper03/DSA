#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char data[10];
    struct node *next;
} *start = NULL;
void create()
{
    struct node *newnode, *ptr;
    char a[10];
    printf("Enter -1 to End:");
    printf("Enter data:");
    scanf("%s", a);

    while (1)
    {
        if (!strcmp(a, "-1"))
            break;
        newnode = (struct node *)malloc(sizeof(struct node));
        strcpy(newnode->data, a);

        newnode->next = NULL;
        if (start == NULL)
        {
            start = newnode;
        }
        else
        {
            ptr = start;
            while (ptr->next != NULL)
                ptr = ptr->next;

            ptr->next = newnode;
        }
        printf("Enter data:");
        scanf("%s", a);
    }
}

void del_all()
{
    char a[10];
    struct node *ptr, *temp;
    printf("Enter character:");
    scanf("%s", a);
    int flag = 1;
    if (!strcmp(start->data, a))
    {
        start = start->next;
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            if (!strcmp(ptr->next->data, a))
            {
                temp = ptr->next;
                ptr->next = temp->next;
                free(temp);
                flag = 0;
            }
        }
    }
}
void del_first()
{
    char a[10];
    struct node *ptr, *temp;
    printf("Enter character:");
    scanf("%s", a);
    if (!strcmp(start->data, a))
    {
        start = start->next;
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            if (!strcmp(ptr->next->data, a))
            {
                temp = ptr->next;
                ptr->next = temp->next;
                free(temp);
                break;
            }
            ptr = ptr->next;
        }
    }
}
void del_last()
{
    char a[10];
    struct node *temp = start, *ptr = NULL;
    printf("Enter character:");
    scanf("%s", a);
    while (temp != NULL)
    {
        if (!strcmp(temp->data, a))
            ptr = temp;
        temp = temp->next;
    }

    // If the last occurrence is the last node
    if (ptr != NULL && ptr->next == NULL)
    {
        temp = start;
        while (temp->next != ptr)
            temp = temp->next;
        temp->next = NULL;
    }

    // If it is not the last node
    if (ptr != NULL && ptr->next != NULL)
    {
        strcpy(ptr->data, ptr->next->data);
        temp = ptr->next;

        ptr->next = ptr->next->next;
        free(temp);
    }
}
void display()
{
    struct node *ptr = start;
    while (ptr != NULL)
    {
        printf("%s ", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    int choice;
    while (1)
    {
        printf("\n1.create:");
        printf("\n2.Display:");
        printf("\n3.del first");
        printf("\n4.del All");
        printf("\n5.del last");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            del_first();
            break;
        case 4:
            del_all();
            break;
        case 5:
            del_last();
            break;
        }
    }
}
