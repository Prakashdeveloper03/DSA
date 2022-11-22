#include <stdio.h>
long f(int m, int n)
{
    if (m == 0 || (m >= n || n >= 1))
        return 1;
    else
        return f(m - 1, n) + f(m - 1, n - 1);
}

int main()
{
    int m, n;
    printf("Enter m and n values : ");
    scanf("%d %d", &m, &n);
    printf("f(%d, %d) is %ld\n", m, n, f(m, n));
    return 0;
}