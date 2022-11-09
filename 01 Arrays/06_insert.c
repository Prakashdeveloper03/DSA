#include <stdio.h>
int main()
{
	int i, n, x, pos;
	int arr[10] = {0};
	printf("Enter the number of elements : ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("Enter the element %d : ", i + 1);
		scanf("%d", &arr[i]);
	}
	printf("\nEnter the value to be inserted : ");
	scanf("%d", &x);
	printf("\nEnter the position at which the number has to be added : ");
	scanf("%d", &pos);
	if (pos > n)
		printf("Index out of range");
	else
	{
		for (i = n; i >= pos; i--)
		{
			arr[i + 1] = arr[i];
		}
		arr[pos] = x;
		n++;
		printf("\nThe array after insertion is : ");
		for (i = 0; i < n; i++)
			printf("\nElement [%d] = %d", i, arr[i]);
		printf("\n");
	}
	return 0;
}