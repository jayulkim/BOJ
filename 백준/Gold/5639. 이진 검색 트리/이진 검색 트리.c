#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[10005] = { 0, };

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

Tree* insert(Tree* root, int num)
{
	if (root == NULL)
	{
		return create(num);
	}
	if (root->data > num)
	{
		root->left = insert(root->left, num);
	}
	else if (root->data < num)
	{
		root->right = insert(root->right, num);
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
	Tree* root = NULL;
	int i = 0;
	while (scanf("%d", &ary[i]) != EOF)
	{
		root = insert(root, ary[i]);
		i++;
	}
	postorder(root);
}