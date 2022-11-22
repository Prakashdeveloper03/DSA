#include <stdio.h>
long lambda(int n)
{
    if (n == 1)
        return 0;
    else
        return lambda(n / 2) + 1;
}

int main()
{
    int n;
    printf("Enter n value : ");
    scanf("%d", &n);
    printf("Lambda(%d) is %ld\n", n, lambda(n));
    return 0;
}
