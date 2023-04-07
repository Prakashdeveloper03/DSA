#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    char info[1000];
    struct node *next;
} node;

void push(node **t, char data[])
{
    node *temp = (node *)malloc(sizeof(node));
    if (temp == NULL)
        printf("Not enough memory\n");
    else
    {
        for (int i = 0; i < data[i] != '\0'; i++)
            temp->info[i] = data[i];
        temp->info[strlen(data)] = '\0';
        if (*t == NULL)
        {
            *t = temp;
            temp->next = NULL;
        }
        else
        {
            temp->next = *t;
            *t = temp;
        }
    }
}

void display(node *t)
{
    if (t == NULL)
        printf("Stack is empty\n");
    else
    {
        while (t != NULL)
        {
            printf("%s\n", t->info);
            t = t->next;
        }
    }
}

int main()
{
    int n;
    char ch;
    char name[100];
    node *top = NULL;
    do
    {
        printf("Enter name of student to be stored in stack: ");
        fflush(stdin);
        scanf("%s", &name);
        push(&top, name);

        printf("Do you want to continue(y/n)?: ");
        fflush(stdin);
        scanf("%c", &ch);
    } while (ch == 'y' || ch == 'Y');
    printf("\nNames stored in stack are:\n");
    display(top);
    return 0;
}