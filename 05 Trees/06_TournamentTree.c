#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
	int key;
	struct Node *left, *right;
};

struct Node *newNode(char k)
{
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
	node->key = k;
	node->right = node->left = NULL;
	return node;
}

unsigned int countNodes(struct Node *root)
{
	if (root == NULL)
		return (0);
	return (1 + countNodes(root->left) + countNodes(root->right));
}

bool isComplete(struct Node *root, unsigned int index,
				unsigned int number_nodes)
{
	if (root == NULL)
		return (true);
	if (index >= number_nodes)
		return (false);
	return (isComplete(root->left, 2 * index + 1, number_nodes) &&
			isComplete(root->right, 2 * index + 2, number_nodes));
}

int main()
{
	struct Node *root = NULL;
	root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->right = newNode(6);
	unsigned int node_count = countNodes(root);
	unsigned int index = 0;
	if (isComplete(root, index, node_count))
		printf("It is a tournament tree\n");
	else
		printf("It is not a tournament tree\n");
	return (0);
}
