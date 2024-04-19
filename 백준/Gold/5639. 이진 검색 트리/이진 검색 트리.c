#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Tree
{
	int data;
	struct Tree* left;
	struct Tree* right;
}Tree;

Tree* create(int num)
{
	Tree* new = (Tree*)malloc(sizeof(Tree));
	new->data = num;
	new->left = NULL;
	new->right = NULL;
	return new;
}

Tree* insert(Tree* root, int target)
{
	if (root == NULL)
	{
		return create(target);
	}
	if (target < root->data)
	{
		root->left = insert(root->left, target);
	}
	else if (target > root->data)
	{
		root->right = insert(root->right, target);
	}
	return root;
}


void postorder(Tree* root)
{
	if (root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d\n", root->data);
	}
}

int main(void)
{
	int num1 = 0;
	Tree* root = NULL;
	while (scanf("%d", &num1) != EOF)
	{
		root = insert(root, num1);
	}
	postorder(root);
}