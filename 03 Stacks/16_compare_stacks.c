#include <stdio.h>
#include <stdlib.h>
struct StackNode
{
    int element;
    struct StackNode *next;
};

struct MyStack
{
    struct StackNode *top;
    int size;
};

struct MyStack *newStack()
{
    struct MyStack *stack = (struct MyStack *)malloc(sizeof(struct MyStack));
    if (stack != NULL)
    {
        stack->top = NULL;
        stack->size = 0;
    }
    else
        printf("\nMemory overflow when create new stack\n");
}

int isEmpty(struct MyStack *stack)
{
    if (stack->size > 0 && stack->top != NULL)
        return 0;
    else
        return 1;
}

void push(struct MyStack *stack, int element)
{
    struct StackNode *node = (struct StackNode *)malloc(sizeof(struct StackNode));

    if (node == NULL)
        printf("\nMemory overflow when create new stack Node \n");
    else
    {
        node->element = element;
        node->next = stack->top;
    }
    stack->top = node;
    stack->size++;
}

int peek(struct MyStack *stack)
{
    return stack->top->element;
}

void pop(struct MyStack *stack)
{
    if (isEmpty(stack) == 0)
    {
        struct StackNode *temp = stack->top;
        stack->top = temp->next;
        free(temp);
        temp = NULL;
        stack->size--;
    }
}

int compareStack(struct MyStack *s1, struct MyStack *s2)
{
    if (s1->size != s2->size)
        return 0;
    struct MyStack *b1 = newStack();
    struct MyStack *b2 = newStack();
    int status = 1;
    while (isEmpty(s1) == 0 && isEmpty(s2) == 0 && status == 1)
    {
        if (peek(s1) != peek(s2))
            status = 0;
        else
        {
            push(b1, peek(s1));
            push(b2, peek(s2));
            pop(s1);
            pop(s2);
        }
    }
    while (isEmpty(b1) == 0)
    {
        push(s1, peek(b1));
        push(s2, peek(b2));
        pop(b1);
        pop(b2);
    }
    return status;
}

void printData(struct MyStack *s)
{
    if (isEmpty(s) == 1)
        return;
    int data = peek(s);
    printf("%d ", data);
    pop(s);
    printData(s);
    push(s, data);
}

void printStack(struct MyStack *s1, struct MyStack *s2)
{
    printf("Stack 1 \n");
    printData(s1);
    printf("\nStack 2 \n");
    printData(s2);
}

int main()
{
    struct MyStack *s1 = newStack();
    struct MyStack *s2 = newStack();
    int n1, n2, value;
    printf("Enter the number of elements to be inserted : ");
    scanf("%d", &n1);
    printf("Enter the values : ");
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &value);
        push(s1, value);
    }
    printf("Enter the number of elements to be inserted : ");
    scanf("%d", &n2);
    printf("Enter the values : ");
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &value);
        push(s2, value);
    }
    printStack(s1, s2);
    if (compareStack(s1, s2) == 1)
        printf("\nStack are equal\n");
    else
        printf("\nStack are not equal\n");
    return 0;
}