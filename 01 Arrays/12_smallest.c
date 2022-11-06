#include <stdio.h>
int smallestElement(int arr[], int n)
{
    int position, smallest;
    smallest = arr[0];
    position = 0;
    for (int i = 0; i < n; i++)
    {
        if (smallest > arr[i])
        {
            smallest = arr[i];
            position = i;
        }
    }
    return position;
}
int main()
{
    int arr[100];
    int n, i, position;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }
    position = smallestElement(arr, n);
    printf("Smallest element of array is %d at position %d\n", arr[position], position + 1);
    return 0;
}