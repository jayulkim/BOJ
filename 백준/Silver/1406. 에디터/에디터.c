#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	char data;
	struct Node* left;
	struct Node* right;
}Node;

void init(Node* head)
{
	head->left = head->right = head;
}
Node* P = NULL;
void insert(Node* prev, int num)
{
	Node* new = (Node*)malloc(sizeof(Node));
	new->data = num;
	new->left = prev;
	new->right = prev->right;
	prev->right->left = new;
	prev->right = new;
	P = new;
}
void delete(Node* head, Node* removed)
{
	if (head == removed)
	{
		return;
	}
	removed->right->left = removed->left;
	removed->left->right = removed->right;
	free(removed);
}
char str[100001];
int main(void)
{
	scanf("%s", str);
	int num1 = strlen(str);
	Node* head = (Node*)malloc(sizeof(Node));
	init(head);
	for (int i = 0; i < num1; i++)
	{
		if (i == 0)
		{
			insert(head, str[i]);
		}
		else
		{
			insert(P, str[i]);
		}
	}
	int num2 = 0;
	scanf("%d", &num2);
	for (int i = 0; i < num2; i++)
	{
		char command;
		scanf(" %c", &command);
		switch (command)
		{
			case 'L':
			{
				if (P != head)
				{
					P = P->left;
				}
				break;
			}
			case 'D':
			{
				if (P->right != head)
				{
					P = P->right;
				}
				break;
			}
			case 'B':
			{
				if (P != head)
				{
					P = P->left;
					delete(head, P->right);
				}
				break;
			}
			case 'P':
			{
				char plus;
				scanf(" %c", &plus);
				if (head->right == head && head->left == head)
				{
					insert(head, plus);
				}
				else
				{
					insert(P, plus);
				}
				break;
			}
		}
	}
	for (Node* i = head->right; i != head; i = i->right)
	{
		printf("%c", i->data);
	}
}