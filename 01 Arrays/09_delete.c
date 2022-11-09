#include <stdio.h>
int main()
{
    int i, j, n, x, temp, arr[50];
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the element %d : ", i);
        scanf("%d", &arr[i]);
    }
    printf("\nEnter a number you want to delete : ");
    scanf("%d", &x);
    for (i = 0; i < n; i++)
    {

        if (arr[i] < x)
            arr[i] = arr[i];
        else
            arr[i] = arr[i + 1];
    }
    n--;
    printf("\nArray after deleting a number are :\n");
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
        printf("Element [%d] = %d\n", i, arr[i]);
    return (0);
}