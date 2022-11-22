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
    int base, pow, result;
    printf("Enter base number: ");
    scanf("%d", &base);
    printf("Enter power number(positive integer): ");
    scanf("%d", &pow);
    result = exp(base, pow);
    printf("%d ^ %d = %d\n", base, pow, result);
    return 0;
}
