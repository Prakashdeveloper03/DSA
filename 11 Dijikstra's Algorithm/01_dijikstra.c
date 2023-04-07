#include <stdio.h>
#include <stdlib.h>
#define INFINITY 999
#define Max 10
int G[Max][Max], cost[Max][Max], adj[Max][Max], pred[Max], dist[Max], visited[Max], nextnode, mindist, count, i, j, k,
    l, m, o, u, n;

void main()
{
    printf("Enter the Number of Vertices: ");
    scanf("%d", &n);
    printf("Enter the Adjacency Matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("Cost of [%c][%c]: ", i + 64, j + 64);
            scanf("%d", &G[i][j]);
        }
    }

    printf("\nThe Adjacency Matrix is:\n");
    printf("\\");

    for (i = 1; i <= n; i++)
    {
        printf("\t%c", i + 64);
    }

    printf("\n");

    for (i = 1; i <= n; i++)
    {
        printf("%c\t", i + 64);
        for (j = 1; j <= n; j++)
        {
            printf("%d\t", G[i][j]);
        }
        printf("\n");
    }

    printf("Enter the Starting Node: ");
    scanf("%d", &u);

    for (i = 1; i <= n; i++)
    {
        dist[i] = G[u][i];
        pred[i] = u;
        visited[i] = 0;
    }

    dist[u] = 0;
    visited[u] = 1;
    count = 1;

    while (count < n - 1)
    {
        mindist = INFINITY;
        for (i = 1; i <= n; i++)
        {
            if (dist[i] < mindist && !visited[i])
            {
                mindist = dist[i];
                nextnode = i;
            }
        }
        visited[nextnode] = 1;
        for (i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                if (mindist + G[nextnode][i] < dist[i])
                {
                    dist[i] = mindist + G[nextnode][i];
                    pred[i] = nextnode;
                }
            }
        }
        count++;
    }

    for (i = 1; i <= n; i++)
    {
        if (i != u)
        {
            if (dist[i] == 999)
                printf("\nPath does not exists (to %c)", i + 64);
            else
            {
                printf("\nDistance from %c to %c is: %d", u + 64, i + 64, dist[i]);
                printf("\nPath: %c", i + 64);
                o = i;
                j = i;
                do
                {
                    j = pred[j];
                    printf(" <-%c", j + 64);
                    m = j;
                    adj[m][o] = G[m][o];
                    o = j;
                } while (j != u);
                printf("\nThe Adjacency Matrix is:\n");
                printf("\\");
                for (k = 1; k <= n; k++)
                {
                    printf("\t%c", k + 64);
                }
                printf("\n");
                for (k = 1; k <= n; k++)
                {
                    printf("%c\t", k + 64);
                    for (l = 1; l <= n; l++)
                    {
                        printf("%d\t", adj[k][l]);
                    }
                    printf("\n");
                }
            }
        }
    }
}
