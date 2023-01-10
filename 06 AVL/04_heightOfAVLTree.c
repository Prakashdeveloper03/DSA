#include <stdio.h>
int AVLtree(int H, int a, int b)
{
	if (H == 0)
		return 1;
	if (H == 1)
		return b;
	return AVLtree(H - 1, b, a + b + 1);
}

int main()
{
	int H;
	printf("\nEnter Height of the Tree: ");
	scanf("%d", &H);
	int a = 1, b = 2;
	int answer = AVLtree(H, a, b);
	printf("n( %d )= %d \n", H, answer);
	return 0;
}
