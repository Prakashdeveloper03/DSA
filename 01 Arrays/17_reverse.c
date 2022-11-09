#include <stdio.h>
int main()
{
    float arr1[50], arr2[50], arr3[100];
    int i, n1, n2, index = 0;
    printf("Enter the number of elements : ");
    scanf("%d", &n1);
    for (i = 0; i < n1; i++)
    {
        printf("Enter the element %d : ", i + 1);
        scanf("%f", &arr1[i]);
    }
    printf("\nEnter the number of elements : ");
    scanf("%d", &n2);
    for (i = 0; i < n2; i++)
    {
        printf("Enter the element %d : ", i + 1);
        scanf("%f", &arr2[i]);
    }
    for (i = 0; i < n1; i++)
    {
        arr3[index] = arr1[i];
        index++;
    }
    for (i = 0; i < n2; i++)
    {
        arr3[index] = arr2[i];
        index++;
    }
    printf("\nMerged array elements : ");
    for (i = index - 1; i >= 0; i--)
        printf("%.2f ", arr3[i]);
    printf("\n");
    return 0;
}