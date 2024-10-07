#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
}Node;
Node* list[1000005];
void init(Node* head)
{
	head->left = head->right = head;
}

void insert(Node* prev, int num)
{
	Node* new = (Node*)malloc(sizeof(Node));
	new->data = num;
	new->left = prev;
	new->right = prev->right;
	prev->right->left = new;
	prev->right = new;
	list[num] = new;
}

int delete(Node* head, Node* removed, char* str)
{
	if (removed == head)
	{
		if (str[0] == 'C' && str[1] == 'N')
		{
			removed = removed->right;
		}
		else if (str[0] == 'C' && str[1] == 'P')
		{
			removed = removed->left;
		}
	}
	int temp = removed->data;
	removed->right->left = removed->left;
	removed->left->right = removed->right;
	free(removed);
	return temp;
}
int ary[500005] = { 0, };
int main(void)
{
	Node* head = (Node*)malloc(sizeof(Node));
	init(head);
	int num1 = 0;
	int num2 = 0;
	scanf("%d %d", &num1, &num2);
	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary[i]);
		if (i == 0)
		{
			insert(head, ary[i]);
		}
		else
		{
			insert(list[ary[i-1]], ary[i]);
		}
	}
	for (int i = 0; i < num2; i++)
	{
		char str[5];
		scanf("%s", str);
		if (str[0] == 'B' && str[1] == 'N')
		{
			int target = 0;
			int number = 0;
			scanf("%d %d", &target, &number);
			if (list[target]->right == head)
			{
				printf("%d\n", list[target]->right->right->data);
			}
			else
			{
				printf("%d\n", list[target]->right->data);
			}
			insert(list[target], number);
		}
		else if (str[0] == 'B' && str[1] == 'P')
		{
			int target = 0;
			int number = 0;
			scanf("%d %d", &target, &number);
			if (list[target]->left == head)
			{
				printf("%d\n", list[target]->left->left->data);
			}
			else
			{
				printf("%d\n", list[target]->left->data);
			}
			insert(list[target]->left, number);
		}
		else if (str[0] == 'C' && str[1] == 'N')
		{
			int target = 0;
			scanf("%d", &target);
			printf("%d\n", delete(head, list[target]->right, str));
		}
		else if (str[0] == 'C' && str[1] == 'P')
		{
			int target = 0;
			scanf("%d", &target);
			printf("%d\n", delete(head, list[target]->left, str));
		}
	}
	
}