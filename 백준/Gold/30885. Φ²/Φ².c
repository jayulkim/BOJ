#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct info
{
	long long int number;
	int index;
}info;

typedef struct Node
{
	info data;
	struct Node* right;
	struct Node* left;
}Node;

Node* point = NULL;

void init(Node* head)
{
	head->left = head->right = head;
}

void insert(Node* prev, long long int number, int index)
{
	Node* new = (Node*)malloc(sizeof(Node));
	new->data.number = number;
	new->data.index = index;
	new->left = prev;
	new->right = prev->right;
	prev->right->left = new;
	prev->right = new;
	point = new;
}

void delete(Node* head, Node* removed)
{
	if (head == removed)
	{
		return;
	}
	removed->left->right = removed->right;
	removed->right->left = removed->left;
	point = removed->left;
	free(removed);
}

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	Node* head = (Node*)malloc(sizeof(Node));
	init(head);
	for (int i = 0; i < num1; i++)
	{
		long long int num2 = 0;
		scanf("%lld", &num2);
		if (i == 0)
		{
			insert(head, num2, i + 1);
		}
		else
		{
			insert(point, num2, i + 1);
		}	
	}
	for (Node* i = head->right; i != head; i = i->right)
	{
	//	printf("%d ", i->data.index);
	}
	while (head->left != head->right)
	{
		for (Node* i = head->right; i != head; i = i->right)
		{
		//	printf("%d ", i->data.index);
			if (i->left == head)
			{
				if (i->right->data.number <= i->data.number)
				{
					i->data.number += i->right->data.number;
					delete(head, i->right);
				}
			}
			else if (i->right == head)
			{
				if (i->left->data.number <= i->data.number)
				{
					i->data.number += i->left->data.number;
					delete(head, i->left);
				}
			}
			else
			{
				if (i->right->data.number <= i->data.number && i->left->data.number <= i->data.number)
				{
					i->data.number += i->right->data.number;
					delete(head, i->right);
					i->data.number += i->left->data.number;
					delete(head, i->left);
				//	printf("%d\n", i->data.index);
				}
				else if (i->right->data.number <= i->data.number && i->left->data.number > i->data.number)
				{
					i->data.number += i->right->data.number;
					delete(head, i->right);
				//	printf("%d\n", i->data.index);
				}
				else if (i->right->data.number > i->data.number && i->left->data.number <= i->data.number)
				{
					i->data.number += i->left->data.number;
					delete(head, i->left);
				//	printf("%d\n", i->data.index);
				}
			}
		}
	}
	for (Node* i = head->right; i != head; i = i->right)
	{
		//	printf("%d ", i->data.index);
	}
	printf("%lld\n%d", head->right->data.number, head->right->data.index);
}
