#include <stdio.h>
#include <stdlib.h>
#define n 10
int h[n];
int insert()
{
    int key, value, i, square, c1 = 0, c2 = 3;
    printf("\nEnter value : ");
    scanf("%d", &value);
    square = value * value;
    for (i = 0; i < n; i++)
    {
        square = square % 10;
        square = square % 10;
        key = (square + c1 * i + c2 * i * i);
        if (h[key] == -1)
        {
            h[key] = value;
            printf("\nKey was inserted at index %d\n", key);
            break;
        }
    }
    if (i > 0)
        printf("\nCollision has happened\n");
}

int display()
{
    for (int i = 0; i < n; i++)
        printf("%d  ", h[i]);
    printf("\n");
}

int main()
{
    int num;
    printf("Enter the no of elements : ");
    scanf("%d", &num);
    for (int i = 0; i < n; i++)
        h[i] = -1;

    for (int i = 0; i < num; i++)
    {
        insert();
        display();
    }
}
