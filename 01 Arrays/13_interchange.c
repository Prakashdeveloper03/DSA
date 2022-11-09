#include <stdio.h>
int main()
{

    int arr[100];
    int n, smallest = 0, largest = 0, i, smallestpos, largestpos, temp;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nThe Array before interchanging the largest and smallest element :\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    smallest = arr[0];
    for (i = 0; i < n; i++)
    {
        if (arr[i] <= smallest)
        {
            smallest = arr[i];
            smallestpos = i;
        }
        if (largest <= arr[i])
        {
            largest = arr[i];
            largestpos = i;
        }
    }
    temp = arr[smallestpos];
    arr[smallestpos] = arr[largestpos];
    arr[largestpos] = temp;

    printf("\n\nThe Array after interchanging the largenst and smallest element :\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}