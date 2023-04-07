#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int coefficient;
    int exponent;
    struct node *next;
} node;

node *create_node(int coefficient, int exponent)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->coefficient = coefficient;
    new_node->exponent = exponent;
    new_node->next = NULL;
    return new_node;
}

void print_polynomial(node *head)
{
    if (head == NULL)
    {
        printf("Polynomial is empty.\n");
        return;
    }
    while (head != NULL)
    {
        printf("%dx^%d ", head->coefficient, head->exponent);
        head = head->next;
        if (head != NULL)
        {
            printf("+ ");
        }
    }
    printf("\n");
}

void insert_term(node **head, int coefficient, int exponent)
{
    node *new_node = create_node(coefficient, exponent);
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    node *prev = NULL;
    node *current = *head;
    while (current != NULL && current->exponent > exponent)
    {
        prev = current;
        current = current->next;
    }
    if (current != NULL && current->exponent == exponent)
    {
        current->coefficient += coefficient;
    }
    else
    {
        if (prev == NULL)
        {
            new_node->next = *head;
            *head = new_node;
        }
        else
        {
            new_node->next = current;
            prev->next = new_node;
        }
    }
}

node *add_polynomials(node *poly1, node *poly2)
{
    node *result = NULL;
    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->exponent == poly2->exponent)
        {
            insert_term(&result, poly1->coefficient + poly2->coefficient, poly1->exponent);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if (poly1->exponent > poly2->exponent)
        {
            insert_term(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        }
        else
        {
            insert_term(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL)
    {
        insert_term(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }
    while (poly2 != NULL)
    {
        insert_term(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }
    return result;
}

node *subtract_polynomials(node *poly1, node *poly2)
{
    node *result = NULL;
    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->exponent == poly2->exponent)
        {
            insert_term(&result, poly1->coefficient - poly2->coefficient, poly1->exponent);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if (poly1->exponent > poly2->exponent)
        {
            insert_term(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        }
        else
        {
            insert_term(&result, -poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL)
    {
        insert_term(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }
    while (poly2 != NULL)
    {
        insert_term(&result, -poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }
    return result;
}

int main()
{
    node *poly1 = NULL;
    node *poly2 = NULL;
    int n1, n2, coefficient, exponent;
    printf("Enter the degree of polynomial 1 : ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
    {
        printf("Enter the coefficient %d : ", i + 1);
        scanf("%d", &coefficient);
        printf("Enter the exponent %d : ", i + 1);
        scanf("%d", &exponent);
        insert_term(&poly1, coefficient, exponent);
    }
    printf("Enter the degree of polynomial 2 : ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
    {
        printf("Enter the coefficient %d : ", i + 1);
        scanf("%d", &coefficient);
        printf("Enter the exponent %d : ", i + 1);
        scanf("%d", &exponent);
        insert_term(&poly2, coefficient, exponent);
    }
    printf("Poly1: ");
    print_polynomial(poly1);
    printf("Poly2: ");
    print_polynomial(poly2);
    node *sum = add_polynomials(poly1, poly2);
    printf("Sum: ");
    print_polynomial(sum);
    node *diff = subtract_polynomials(poly1, poly2);
    printf("Difference: ");
    print_polynomial(diff);
    return 0;
}