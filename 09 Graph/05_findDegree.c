#include <stdio.h>
int adj[100][100], n;
int main()
{
    int maxe, i, j, org, des = 0;
    int count = 0;
    printf("Enter vertice of graph : ");
    scanf("%d", &n);
    maxe = n * (n - 1);
    for (i = 1; i <= maxe; i++)
    {
        printf("Enter Edge of vertices %d \nPress -1 for Stop\n", i);
        scanf("%d %d", &org, &des);
        if ((org == -1) && (des == -1))
            break;

        if (org >= n || des >= n || org < 0 || des < 0)
        {
            printf("Invalid Input\n");
            i--;
        }
        else
        {
            adj[org][des] = 1;
            count++;
        }
    }
    printf("Adjancy Matrix is \n");
    for (i = 0; i < n; i++)
        printf("%4d", i);
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("%d", i);
        for (j = 0; j < n; j++)
        {
            printf("%4d", adj[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < n; i++)
    {
        count = 0;
        for (j = 0; j < n; j++)
            if (adj[j][i] == 1)
                count++;
        printf("Degree of vertex %d is %d\n", i + 1, count);
    }
    return 0;
}