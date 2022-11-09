#include <stdio.h>
int main()
{
    int arr[100];
    int n, i, temp;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("\nThe Array before interchanging the 2nd element and 2nd last element :\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    temp = arr[1];
    arr[1] = arr[n - 2];
    arr[n - 2] = temp;
    printf("\nThe Array after interchanging the 2nd element and 2nd last element :\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}