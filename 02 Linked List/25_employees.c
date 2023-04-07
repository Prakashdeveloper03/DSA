#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee
{
    char name[50];
    int emp_id;
    float salary;
    struct employee *next;
};

struct employee *create_employee(char name[], int emp_id, float salary)
{
    struct employee *emp = (struct employee *)malloc(sizeof(struct employee));
    strcpy(emp->name, name);
    emp->emp_id = emp_id;
    emp->salary = salary;
    emp->next = NULL;
    return emp;
}

void print_list(struct employee *head)
{
    struct employee *current = head;
    while (current != NULL)
    {
        printf("Name: %s\n", current->name);
        printf("Employee ID: %d\n", current->emp_id);
        printf("Salary: %.2f\n\n", current->salary);
        current = current->next;
    }
}

int main()
{
    struct employee *head = NULL;

    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        char name[50];
        int emp_id;
        float salary;
        printf("\nEnter details for employee %d:\n", i + 1);
        printf("Enter name: ");
        scanf(" %[^\n]s", name);
        printf("Enter employee ID: ");
        scanf("%d", &emp_id);
        printf("Enter salary: ");
        scanf("%f", &salary);
        struct employee *emp = create_employee(name, emp_id, salary);
        if (head == NULL)
        {
            head = emp;
        }
        else
        {
            struct employee *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = emp;
        }
    }

    printf("\nEmployee Details:\n");
    print_list(head);
    return 0;
}