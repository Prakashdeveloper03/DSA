#include <stdio.h>
int main()
{
    int arr[100];
    int n, i, smallest, position;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }
    smallest = arr[0];
    position = 0;
    for (i = 0; i < n; i++)
    {
        if (smallest > arr[i])
        {
            smallest = arr[i];
            position = i;
        }
    }
    printf("Smallest element of array is %d at position %d\n", smallest, position + 1);
    return 0;
}