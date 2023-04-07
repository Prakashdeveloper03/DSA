#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *getNode(int data)
{
    struct node *fresh = (struct node *)malloc(sizeof(struct node));
    fresh->data = data;
    fresh->left = fresh->right = NULL;
    return fresh;
}

struct node *insertLevelWise(int arr[], struct node *root, int i, int n)
{
    if (i < n)
    {
        struct node *temp = getNode(arr[i]);
        root = temp;
        root->left = insertLevelWise(arr, root->left, 2 * i + 1, n);
        root->right = insertLevelWise(arr, root->right, 2 * (i + 1), n);
    }
    return root;
}

void preorderTrav(struct node *root)
{
    if (root != NULL)
    {

        printf("%d ", root->data);
        preorderTrav(root->left);
        preorderTrav(root->right);
    }
}

int main()
{
    int arr[20];
    int s;
    printf("Enter the size of Array: ");
    scanf("%d", &s);
    for (int i = 0; i < s; i++)
    {
        printf("Enter Element %d ", i + 1);
        scanf("%d", &arr[i]);
    }
    struct node *root = insertLevelWise(arr, root, 0, s);
    printf("Preorder traversal of created tree: \n");
    preorderTrav(root);
}