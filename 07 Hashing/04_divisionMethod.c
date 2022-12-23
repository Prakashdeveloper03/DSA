#include <stdio.h>
#include <stdlib.h>
#define n 9
int h[n];
int insert()
{
	int key, value;
	int i;
	printf("\nEnter value : ");
	scanf("%d", &value);
	for (i = 0; i < n; i++)
	{
		key = value % 10 + i;
		if (h[key] == -1)
		{
			h[key] = value;
			printf("\nKey was inserted at index %d\n", key);
			break;
		}
	}
	if (i > 0)
		printf("\nCollision has happened\n");
}

int display()
{
	for (int i = 0; i < n; i++)
		printf("%d  ", h[i]);
	printf("\n");
}

int main()
{
	int num;
	printf("Enter the no of elements : ");
	scanf("%d", &num);
	for (int i = 0; i < n; i++)
		h[i] = -1;

	for (int i = 0; i < num; i++)
	{
		insert();
		display();
	}
}
