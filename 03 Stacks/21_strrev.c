#include <stdio.h>
#include <string.h>
void reverse(char *str1)
{
    int len, temp;
    len = strlen(str1);
    for (int i = 0; i < len / 2; i++)
    {
        temp = str1[i];
        str1[i] = str1[len - i - 1];
        str1[len - i - 1] = temp;
    }
}

int main()
{
    char str[50];
    printf("Enter the string : ");
    gets(str);
    printf("\nBefore reversing thestring: %s\n\n", str);
    reverse(str);
    printf("\nAfter reversing the string: %s\n\n", str);
}
