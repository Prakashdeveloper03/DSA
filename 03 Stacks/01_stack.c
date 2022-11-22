#include <stdio.h>
#include <stdlib.h>
int stack[10], top = -1, n = 10;
void push(int value)
{
  if (top == n - 1)
    printf("Stack Overflow...");
  else
  {
    top++;
    stack[top] = value;
  }
}

int pop()
{
  int item;
  if (top == -1)
    printf("Stack Underflow...");
  else
  {
    item = stack[top];
    top--;
  }
  return item;
}

void peek()
{
  if (top == -1)
    printf("Stack is empty...");
  else
    printf("The peek of the stack is %d\n", stack[top]);
}

void display()
{
  for (int i = top; i > -1; i--)
  {
    printf("%d ", stack[i]);
  }
  printf("\n\n");
}

int main()
{
  int choice, value;
  printf("\nImplementation of Stack using arrays");
  while (1)
  {
    printf("\n1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit");
    printf("\nEnter your choice : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("\nEnter the value to insert: ");
      scanf("%d", &value);
      push(value);
      break;
    case 2:
      printf("Popped element is :%d\n", pop());
      break;
    case 3:
      display();
      break;
    case 4:
      peek();
      break;
    case 5:
      exit(0);
      break;
    default:
      printf("\nWrong Choice\n");
    }
  }
}
