#include <stdio.h>
int main()
{
    int i, n, pos;
    float x, arr[10];
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the element %d : ", i);
        scanf("%f", &arr[i]);
    }
    printf("\nEnter the value to be inserted : ");
    scanf("%f", &x);
    printf("\nEnter the position at which the number has to be added : ");
    scanf("%d", &pos);
    for (i = n; i >= pos; i--)
        arr[i + 1] = arr[i];
    arr[pos] = x;
    n++;
    printf("\nThe array after insertion is : ");
    for (i = 0; i < n; i++)
    {
        printf("\nElement [%d] = %.3f", i, arr[i]);
    }
    printf("\n");
    return 0;
}