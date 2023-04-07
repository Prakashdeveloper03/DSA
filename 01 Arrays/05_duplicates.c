#include <stdio.h>
int main()
{
    int arr[100];
    int n, status = 0;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
                status = 1;
        }
    }
    if (status)
        printf("Array having duplicates\n");
    else
        printf("Array having no duplicates\n");
    return 0;
}
