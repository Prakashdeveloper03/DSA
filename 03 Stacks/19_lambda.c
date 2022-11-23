#include <stdio.h>
long lambda(int n)
{
    if (n == 0)
        return 1;
    else if (n > 0)
        return lambda(n / 2) + 1;
    else
        return 0;
}

int main()
{
    int n;
    printf("Enter n value : ");
    scanf("%d", &n);
    printf("Lambda(%d) is %ld\n", n, lambda(n));
    return 0;
}
