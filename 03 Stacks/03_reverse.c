#include <stdio.h>
int main()
{
    int arr[50];
    int i, n;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("\nReversed list of elements : ");
    for (i = n - 1; i >= 0; i--)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}