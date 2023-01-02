
#include <stdio.h>
#include <stdlib.h>
#define COUNT 10
struct node
{
    struct node *lchild;
    int info;
    struct node *rchild;
};

struct node *insert(struct node *ptr, int key)
{
    if (ptr == NULL)
    {
        ptr = (struct node *)malloc(sizeof(struct node *));
        ptr->info = key;
        ptr->lchild = NULL;
        ptr->rchild = NULL;
    }
    else if (key < ptr->info)
    {
        ptr->lchild = insert(ptr->lchild, key);
    }
    else if (key > ptr->info)
    {
        ptr->rchild = insert(ptr->rchild, key);
    }
    else
        printf("\nDuplicate key:");
    return ptr;
}

struct node *search(struct node *ptr, int key)
{
    if (ptr == NULL)
    {
        return NULL;
    }
    else if (key < ptr->info)
        return search(ptr->lchild, key);
    else if (key > ptr->info)
        return search(ptr->rchild, key);
    return ptr;
}

int main()
{
    struct node *ptr, *root = NULL;
    int choice, key;
    while (1)
    {
        printf("\n1.INSERT");
        printf("\n2.Search Operation");
        printf("\nEnter your choice::");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Key:");
            scanf("%d", &key);
            root = insert(root, key);
            break;
        case 2:
            printf("Enter the key to be Deleted:");
            scanf("%d", &key);
            root = del(root, key);
            break;
        case 3:
            printf("Total Node:%d", count(root));
            break;
        case 4:
            print2D(root);
            break;
        case 5:
            exit(0);
        default:
            printf("\nInvalid Choice\n");
            break;
        }
    }
}
