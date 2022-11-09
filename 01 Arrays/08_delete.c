
#include <stdio.h>
int main()
{
    int i, n, pos;
    int arr[10];
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the element %d : ", i);
        scanf("%d", &arr[i]);
    }
    printf("\nEnter the index at which the number has to be deleted : ");
    scanf("%d", &pos);
    if (pos >= n)
        printf("Position Overflow\n");
    else
    {
        for (i = 0; i <= n; i++)
        {
            if (i < pos)
                arr[i] = arr[i];
            else
                arr[i] = arr[i + 1];
        }
        n--;
        printf("\nThe array after deletion is : ");
        for (i = 0; i < n; i++)
            printf("\nElement [%d] = %d", i, arr[i]);
        printf("\n");
    }
    return 0;
}
