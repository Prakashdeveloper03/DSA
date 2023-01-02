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
        ptr->lchild = insert(ptr->lchild, key);
    else if (key > ptr->info)
        ptr->rchild = insert(ptr->rchild, key);
    else
        printf("\nDuplicate key\n");
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

int count(struct node *ptr)
{
    int x, y;
    if (ptr != NULL)
    {
        x = count(ptr->lchild);
        y = count(ptr->rchild);
        return x + y + 1;
    }
    return 0;
}

struct node *del(struct node *ptr, int key)
{
    struct node *temp, *succ;
    if (ptr == NULL)
    {
        printf("Key Not Found:");
        return ptr;
    }
    if (key < ptr->info)
        ptr->lchild = del(ptr->lchild, key);
    else if (key > ptr->info)
        ptr->rchild = del(ptr->rchild, key);
    else
    {
        if (ptr->lchild != NULL && ptr->rchild != NULL)
        {
            succ = ptr->rchild;
            while (succ->lchild)
                succ = succ->lchild;
            ptr->info = succ->info;
            ptr->rchild = del(ptr->rchild, succ->info);
        }
        else
        {
            temp = ptr;
            if (ptr->lchild != NULL)
                ptr = ptr->lchild;
            else if (ptr->rchild != NULL)
                ptr = ptr->rchild;
            else
                ptr = NULL;
            free(temp);
        }
    }
    return ptr;
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
        printf("\n01. Insert");
        printf("\n02. Search");
        printf("\n03. Inorder");
        printf("\n04. Preorder");
        printf("\n05. Postorder");
        printf("\n06. Total no of nodes");
        printf("\n07. Delete");
        printf("\n08. Print Tree");
        printf("\n09. Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Key : ");
            scanf("%d", &key);
            root = insert(root, key);
            break;
        case 2:
            printf("Enter the key to search : ");
            scanf("%d", &key);
            ptr = search(root, key);
            if (ptr == NULL)
                printf("Key not present\n");
            else
                printf("Key present\n");
            break;
        case 3:
            printf("\n Inorder traversal : ");
            inorder(root);
            break;
        case 4:
            printf("\n Preorder traversal : ");
            preorder(root);
            break;
        case 5:
            printf("\n Postorder traversal : ");
            postorder(root);
            break;
        case 6:
            printf("Total Node : %d", count(root));
            break;
        case 7:
            printf("Enter the key to be deleted : ");
            scanf("%d", &key);
            root = del(root, key);
            break;
        case 8:
            print2D(root);
            break;
        case 9:
            exit(0);
        default:
            printf("\nInvalid Choice\n");
            break;
        }
    }
}
