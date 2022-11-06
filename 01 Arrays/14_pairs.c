#include <stdio.h>
int main()
{
    int arr[100];
    int n, i;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] + arr[j] == 50)
                printf("(%d, %d) ", arr[i], arr[j]);
    printf("\n");
    return 0;
}
