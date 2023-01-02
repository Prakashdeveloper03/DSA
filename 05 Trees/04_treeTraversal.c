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
void inorder(struct node *ptr)
{
    if (ptr == NULL)
    {
        return;
    }

    inorder(ptr->lchild);
    printf("%d ", ptr->info);
    inorder(ptr->rchild);
}
void preorder(struct node *ptr)
{

    if (ptr == NULL)
    {
        return;
    }
    printf("%d ", ptr->info);
    preorder(ptr->lchild);
    preorder(ptr->rchild);
}
void postorder(struct node *ptr)
{

    if (ptr == NULL)
    {
        return;
    }

    postorder(ptr->lchild);
    postorder(ptr->rchild);
    printf("%d ", ptr->info);
}

void print2DUtil(struct node *root, int space)
{
    int i;
    if (root == NULL)
        return;
    space += COUNT;
    print2DUtil(root->rchild, space);
    printf("\n");
    for (i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->info);
    print2DUtil(root->lchild, space);
}
void print2D(struct node *root)
{
    print2DUtil(root, 0);
}

int main()
{
    struct node *ptr, *root = NULL;
    int choice, key;
    while (1)
    {
        printf("\n1.INSERT");
        printf("\n2.Tree Traversal Methods");
        printf("\n3.Print Tree:");
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
            printf("\n****InOrder Traversal****\n");
            inorder(root);
            printf("\n****PostOrder Traversal****\n");
            preorder(root);
            printf("\n****PreOrder Traversal****\n");
            postorder(root);
            printf("\n\n****Tree In 2D ****");
            print2D(root);
        }
    }
}
