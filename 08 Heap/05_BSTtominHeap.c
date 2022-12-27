#include <stdio.h>
#include <stdlib.h>
int counter = 10, heap[50], gap = 1, n = 0;
int swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int heapify(int i)
{
	int largest = i, left = (2 * i) + 1, right = (2 * i) + 2;
	if (left < n && heap[left] < heap[largest])
		largest = left;
	if (right < n && heap[right] < heap[largest])
		largest = right;
	if (largest != i)
	{
		swap(&heap[i], &heap[largest]);
		heapify(largest);
	}
}

int insertHeap(int value)
{
	int j;
	heap[n] = value;
	n++;
	for (j = n / 2 - 1; j >= 0; j--)
		heapify(j);
	return n;
}

int display(int n, int i, int space)
{
	int left, right, j;
	if (i < n)
	{
		space = space + gap;
		left = (2 * i) + 1;
		right = (2 * i) + 2;
		display(n, right, space);
		printf("\n");
		for (j = space; j > 0; j--)
			printf("\t");
		printf("%d\n", heap[i]);
		display(n, left, space);
	}
}

struct node
{
	int data;
	struct node *left;
	struct node *right;
} *root = NULL;

struct node *insert(struct node *root, int key)
{
	if (root == NULL)
	{
		root = (struct node *)malloc(sizeof(struct node));
		root->data = key;
		root->left = NULL;
		root->right = NULL;
	}
	else if (key < root->data)
		root->left = insert(root->left, key);
	else if (key > root->data)
		root->right = insert(root->right, key);
	return root;
}

int inorder(struct node *root)
{
	if (root == NULL)
		return 0;
	else
	{
		inorder(root->left);
		n = insertHeap(root->data);
		inorder(root->right);
	}
}

int printTree(struct node *root, int space)
{
	int i;
	if (root == NULL)
		return 0;
	space += counter;
	printTree(root->right, space);
	for (i = counter; i < space; i++)
		printf(" ");
	printf("%d\n", root->data);
	printTree(root->left, space);
}

int main()
{
	int i, key, num;
	printf("Enter the number of elements to be inserted : ");
	scanf("%d", &num);
	printf("BST to Min Heap");
	for (i = 0; i < num; i++)
	{
		printf("\nEnter value : ");
		scanf("%d", &key);
		root = insert(root, key);
		printTree(root, 0);
	}
	inorder(root);
	printf("\n\n");
	display(n, 0, 0);
}
