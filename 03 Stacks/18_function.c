#include <stdio.h>
long f(int r, int n)
{
    if (r == 0)
        return 1;
    else if (n == 0)
        return 1;
    else
        return f(n - 1, r) + f(n - 1, r - 1);
}

int main()
{
    int r, n;
    printf("Enter r and n values : ");
    scanf("%d %d", &r, &n);
    printf("f(%d, %d) is %ld\n", r, n, f(r, n));
    return 0;
}
