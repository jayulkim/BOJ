#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[30][5];

typedef struct Tree
{
	char data;
	struct Tree* left;
	struct Tree* right;
}Tree;

Tree* create(char str)
{
	Tree* new = (Tree*)malloc(sizeof(Tree));
	new->data = str;
	new->left = new->right = NULL;
	return new;
}
Tree* createleft(Tree* root, char str)
{
	Tree* new = (Tree*)malloc(sizeof(Tree));
	new->data = str;
	new->left = new->right = NULL;
	root->left = new;
	return root;
}
Tree* createright(Tree* root, char str)
{
	Tree* new = (Tree*)malloc(sizeof(Tree));
	new->data = str;
	new->left = new->right = NULL;
	root->right = new;
	return root;
}
void inorder(Tree* root, char target, char left, char right)
{
	if (root != NULL)
	{
		inorder(root->left, target, left, right);
		if (root->data == target)
		{
			if (left != '.')
			{
				root = createleft(root, left);
			}
			if (right != '.')
			{
				root = createright(root, right);
			}
			return;
		}
		inorder(root->right, target, left, right);
	}
}
void inorder1(Tree* root)
{
	if (root != NULL)
	{
		inorder1(root->left);
		printf("%c", root->data);
		inorder1(root->right);
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
		
		scanf(" %c %c %c", &str[i][0], &str[i][1], &str[i][2]);
	}
	Tree* root = create(str[0][0]);
	if (str[0][1] != '.')
	{
		root = createleft(root, str[0][1]);
	}
	if (str[0][2] != '.')
	{
		root = createright(root, str[0][2]);
	}
	
	while (1)
	{
		int count = 0;
		for (int i = 1; i < num1; i++)
		{
			if (str[i][0] == NULL)
			{
				count++;
			}
			else
			{
				inorder(root, str[i][0], str[i][1], str[i][2]);
				str[i][0] = NULL;
			}
		}
		if (count == num1 - 1)
		{
			break;
		}
	}
	preorder(root);
	printf("\n");
	inorder1(root);
	printf("\n");
	postorder(root);
}