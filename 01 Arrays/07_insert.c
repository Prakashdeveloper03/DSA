
#include <stdio.h>
int main()
{
    int i, j, n, x, temp, arr[50];
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("\nEnter the value to be inserted : ");
    scanf("%d", &x);
    arr[n] = x;
    n++;
    printf("\nThe array after insertion is : ");
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
        printf("\nElement [%d] = %d", i, arr[i]);
    printf("\n");
    return 0;
}
