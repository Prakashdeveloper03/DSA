#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

void printArray(int ints[], int len)
{
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", ints[i]);
    printf("\n");
}

void printPathsRecur(struct node *node, int path[], int pathLen)
{
    if (node == NULL)
        return;
    path[pathLen] = node->data;
    pathLen++;
    if (node->left == NULL && node->right == NULL)
        printArray(path, pathLen);
    else
    {
        printPathsRecur(node->left, path, pathLen);
        printPathsRecur(node->right, path, pathLen);
    }
}

void printPaths(struct node *node)
{
    int path[1000];
    printPathsRecur(node, path, 0);
}

struct node *newnode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

int main()
{
    struct node *root = newnode(10);
    root->left = newnode(8);
    root->right = newnode(2);
    root->left->left = newnode(3);
    root->left->right = newnode(5);
    root->right->left = newnode(2);
    printPaths(root);
    getchar();
    return 0;
}