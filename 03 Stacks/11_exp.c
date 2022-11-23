#include <stdio.h>
int exp(int base, int pow)
{
    if (pow != 0)
        return (base * exp(base, pow - 1));
    else
        return 1;
}

int main()
{
    int base, pow;
    printf("Enter base number: ");
    scanf("%d", &base);
    printf("Enter power number(positive integer): ");
    scanf("%d", &pow);
    printf("%d ^ %d = %d\n", base, pow, exp(base, pow));
    return 0;
}
