#include <stdio.h>
long f(int x, int y)
{
    if (x < y)
        return 0;
    else
        return f(x - y, y) + 1;
}

int main()
{
    int x, y;
    printf("Enter x and y values : ");
    scanf("%d %d", &x, &y);
    printf("f(%d, %d) is %ld\n", x, y, f(x, y));
    return 0;
}
