#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	char data;
	struct Node* right;
	struct Node* left;
}Node;

void init(Node* head)
{
	head->left = head->right = head;
}

Node* insert(Node* prev, char str)
{
	Node* new = (Node*)malloc(sizeof(Node));
	new->data = str;
	new->left = prev;
	new->right = prev->right;
	prev->right->left = new;
	prev->right = new;
	return new;
}

void delete(Node* head, Node* removed)
{
	if (removed == head)
	{
		return;
	}
	removed->left->right = removed->right;
	removed->right->left = removed->left;
	//free(removed);
}

char str[100005];

int main(void)
{
	scanf("%s", str);
	int num1 = strlen(str);
	Node* head = (Node*)malloc(sizeof(Node));
	init(head);
	Node* point = NULL;
	point = insert(head, str[0]);
	for (int i = 1; i < num1; i++)
	{
		point = insert(point, str[i]);
	}
	for (Node* i = head->right; i != head; i = i->right)
	{
		//printf("%c", i->data);
	}
	int num2 = 0;
	scanf("%d", &num2);
	for (int i = 0; i < num2; i++)
	{
		char command;
		char str1;
		scanf(" %c", &command);
		//printf("%d\n", command);
		if (command == 'P')
		{
			scanf(" %c", &str1);
			point = insert(point, str1);
		}
		else if (command == 'L')
		{
			if (point != head)
			{
				point = point->left;
			}
		}
		else if (command == 'D')
		{
			if (point->right != head)
			{
				point = point->right;
			}
		}
		else if (command == 'B')
		{
			if (point != head)
			{	
				delete(head, point);
				point = point->left;
			}
		}
	}
	for (Node* i = head->right; i != head; i = i->right)
	{
		printf("%c", i->data);
	}
}
