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
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
