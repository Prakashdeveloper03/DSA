#include <stdio.h>
int main()
{
    int arr[100];
    int n, i, largest = 0, secondLargest;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("arr[%d] : ", i);
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
    }
    printf("The Second Largest number in the array is %d\n", secondLargest);
    return 0;
}