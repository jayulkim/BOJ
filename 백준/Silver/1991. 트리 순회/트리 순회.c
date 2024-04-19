#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Tree
{
	char data;
	struct Tree* left;
	struct Tree* right;
}Tree;

char node[30][5];

Tree* create(char num)
{
	Tree* new = (Tree*)malloc(sizeof(Tree));
	new->data = num;
	new->left = NULL;
	new->right = NULL;
	return new;
}
void inorderinsert(Tree* root, char target, int forward, char new)
{
	if (root != NULL)
	{
		inorderinsert(root->left, target, forward, new);
		if (root->data == target)
		{
			if (forward == 0)
			{
				root->left = create(new);
			}
			else if (forward == 1)
			{
				root->right = create(new);
			}
		}
		inorderinsert(root->right, target, forward, new);
	}
}
void preorder(Tree* root)
{
	if (root != NULL)
	{
		printf("%c", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(Tree* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%c", root->data);
		inorder(root->right);
	}
}
void postorder(Tree* root)
{
	if (root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%c", root->data);
	}
}

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	
	for (int i = 0; i < num1; i++)
	{
		scanf(" %c %c %c", &node[i][0], &node[i][1], &node[i][2]);
	}
	Tree* root = create(node[0][0]);
	for (int i = 0; i < num1; i++)
	{
		if (node[i][1] != '.')
		{
			inorderinsert(root, node[i][0], 0, node[i][1]);
		}
		if (node[i][2] != '.')
		{
			inorderinsert(root, node[i][0], 1, node[i][2]);
		}
	}
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
}