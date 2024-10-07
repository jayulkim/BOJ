#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

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
	free(removed);
}

char str[1000005];

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%s", str);
		int num1 = strlen(str);
		Node* head = (Node*)malloc(sizeof(Node));
		init(head);
		Node* point = NULL;
		
		int count = 0;
		for (int j = 0; j < num1; j++)
		{
			if (str[j] != '<' && str[j] != '>' && str[j] != '-')
			{
				if (count == 0)
				{
					point = insert(head, str[j]);
					count++;
				}
				else
				{
					point = insert(point, str[j]);
				}
			}
			else
			{
				if (count != 0)
				{
					if (str[j] == '<')
					{
						if (point != head)
						{
							point = point->left;
						}
					}
					else if (str[j] == '>')
					{
						if (point->right != head)
						{
							point = point->right;
						}
					}
					else if (str[j] == '-')
					{
						if (point != head)
						{
							Node* removed = point;
							delete(head, removed);
							point = point->left;
						}
					}
				}
			}
		}

		for (Node* j = head->right; j != head; j = j->right)
		{
			printf("%c", j->data);
		}
		printf("\n");
		memset(str, NULL, sizeof(str));
	}

	
}
