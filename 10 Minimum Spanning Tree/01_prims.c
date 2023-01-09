#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define TEMP 0
#define PREM 1
#define infinity 9999
#define NIL -1
struct edge
{
	int u;
	int v;
};
int n, adj[MAX][MAX], predecessor[MAX], status[MAX], length[MAX];
int min_temp()
{
	int i;
	int min = infinity;
	int k = -1;
	for (i = 0; i < n; i++)
	{
		if (status[i] == TEMP && length[i] < min)
		{
			min = length[i];
			k = i;
		}
	}
	return k;
}

void create_graph()
{
	int i, j, wt, edges, origin, distin;
	printf("Enter the number of vertex : ");
	scanf("%d", &n);
	edges = n * (n - 1);
	for (i = 0; i < edges; i++)
	{
		printf("Enter the %d edges(-1 -1 to Exit)\n", i);
		scanf("%d %d", &origin, &distin);
		if (origin == -1 || distin == -1)
			break;
		printf("Enter the weight for this edge : ");
		scanf("%d", &wt);
		if (origin >= n || origin < 0 || distin >= n || distin < 0)
		{
			printf("Invalid");
			i--;
		}
		else
		{
			adj[origin][distin] = wt;
			adj[distin][origin] = wt;
		}
	}
}

void maketree(int r, struct edge tree[MAX])
{
	int current, i;
	int count = 0;
	for (i = 0; i < n; i++)
	{
		predecessor[i] = NIL;
		length[i] = infinity;
		status[i] = TEMP;
	}
	length[r] = 0;
	while (1)
	{
		current = min_temp();
		if (current == NIL)
		{
			if (count == n - 1)
				return;
			else
			{
				printf("Graph is not connected:");
				exit(1);
			}
		}
		status[current] = PREM;
		if (current != r)
		{
			count++;
			tree[count].u = predecessor[current];
			tree[count].v = current;
		}
		for (i = 0; i < n; i++)
		{
			if (adj[current][i] > 0 && status[i] == TEMP)
			{
				if (adj[current][i] < length[i])
				{
					predecessor[i] = current;
					length[i] = adj[current][i];
				}
			}
		}
	}
}

int main()
{
	int wt_tree = 0;
	int i, root;
	struct edge tree[MAX];
	create_graph();
	printf("Enter root vertex : ");
	scanf("%d", &root);
	maketree(root, tree);
	printf("Edge to be included in spanning tree are : \n");
	for (i = 1; i <= n - 1; i++)
	{
		printf("%d -> ", tree[i].u);
		printf("%d\n", tree[i].v);
		wt_tree += adj[tree[i].u][tree[i].v];
	}
	printf("Weight of the spanning tree is %d\n", wt_tree);
}