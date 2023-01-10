#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

struct tree
{
    char data;
    struct tree *left, *right;
};

int top = -1;
struct tree *stack[20];
struct tree *node;

int check(char ch)
{
    if (ch == '+' || ch == '-' || ch == '/' || ch == '*')
        return 2;
    else
        return 1;
}

void push(struct tree *node)
{
    stack[++top] = node;
}

struct tree *pop()
{
    return (stack[top--]);
}

int cal(struct tree *node)
{
    int ch;
    ch = check(node->data);
    if (ch == 1)
        return node->data - 48;
    else if (ch == 2)
    {
        if (node->data == '+')
            return cal(node->left) + cal(node->right);
        if (node->data == '-')
            return cal(node->left) - cal(node->right);
        if (node->data == '*')
            return cal(node->left) * cal(node->right);
        if (node->data == '/')
            return cal(node->left) / cal(node->right);
    }
}

void inorder(struct tree *node)
{
    if (node != NULL)
    {
        inorder(node->left);
        printf("%c", node->data);
        inorder(node->right);
    }
}

void operand(char b)
{
    node = (struct tree *)malloc(sizeof(struct tree));
    node->data = b;
    node->left = NULL;
    node->right = NULL;
    push(node);
}

void operators(char a)
{
    node = (struct tree *)malloc(sizeof(struct tree));
    node->data = a;
    node->right = pop();
    node->left = pop();
    push(node);
}

int main(int argc, char **argv)
{
    int i, p, k, ans;
    char s[20];
    printf("Enter the expression in postfix form \n");
    fflush(stdin);
    gets(s);
    k = strlen(s);
    i = 0;
    for (i = 0; s[i] != '\0'; i++)
    {
        p = check(s[i]);
        if (p == 1)
            operand(s[i]);
        else if (p == 2)
            operators(s[i]);
    }
    ans = cal(stack[top]);
    printf("\nThe value of the postfix expression you entered is %d\n", ans);
    printf("\nThe inorder traversal of the tree is \n");
    inorder(stack[top]);
    return 0;
}