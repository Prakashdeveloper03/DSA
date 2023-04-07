#include <stdio.h>
int heap1[50], gap = 1, heap2[50];
int swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int maxheapify(int n, int i)
{
    int largest = i, left = (2 * i) + 1, right = (2 * i) + 2;
    if (left < n && heap1[left] > heap1[largest])
        largest = left;
    if (right < n && heap1[right] > heap1[largest])
        largest = right;
    if (largest != i)
    {
        swap(&heap1[i], &heap1[largest]);
        maxheapify(n, largest);
    }
}

int maxinsert(int n)
{
    int value, j;
    printf("\nEnter the value = ");
    scanf("%d", &value);
    heap1[n] = value;
    n++;
    for (j = n / 2 - 1; j >= 0; j--)
        maxheapify(n, j);
    return n;
}

int minheapify(int n1, int i)
{
    int largest = i, left = (2 * i) + 1, right = (2 * i) + 2;
    if (left < n1 && heap2[left] < heap2[largest])
        largest = left;
    if (right < n1 && heap2[right] < heap2[largest])
        largest = right;
    if (largest != i)
    {
        swap(&heap2[i], &heap2[largest]);
        minheapify(n1, largest);
    }
}

int mininsert(int n1, int value)
{
    int j;
    heap2[n1] = value;
    n1++;
    for (j = n1 / 2 - 1; j >= 0; j--)
        minheapify(n1, j);
    return n1;
}

int display1(int n, int i, int space)
{
    int left, right, j;
    if (i < n)
    {
        space = space + gap;
        left = (2 * i) + 1;
        right = (2 * i) + 2;
        display1(n, right, space);
        printf("\n");
        for (j = space; j > 0; j--)
            printf("\t");
        printf("%d\n", heap1[i]);
        display1(n, left, space);
    }
}

int display2(int n1, int i, int space)
{
    int left, right, j;
    if (i < n1)
    {
        space = space + gap;
        left = (2 * i) + 1;
        right = (2 * i) + 2;
        display2(n1, right, space);
        printf("\n");
        for (j = space; j > 0; j--)
            printf("\t");
        printf("%d\n", heap2[i]);
        display2(n1, left, space);
    }
}

int main()
{
    int i, num, n1 = 0, n2 = 0;
    printf("Enter the number of elements to be inserted : ");
    scanf("%d", &num);
    printf("Max heap to Min heap");
    for (i = 0; i < num; i++)
    {
        n1 = maxinsert(n1);
        display1(n1, 0, 0);
    }
    printf("\n\n");
    for (i = 0; i < n1; i++)
        n2 = mininsert(n2, heap1[i]);
    display2(n2, 0, 0);
}
