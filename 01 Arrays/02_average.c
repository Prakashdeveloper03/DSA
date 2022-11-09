#include <stdio.h>
int main()
{
	int arr[100];
	int n, i, sum = 0;
	printf("Enter the number of elements : ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("Enter the element %d : ", i + 1);
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < n; i++)
		sum += arr[i];
	float avg = sum / n;
	printf("The Average is %.2f\n", avg);
	return 0;
}
