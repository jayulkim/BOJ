#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
char target[30];
char frontstack[300005];
char backstack[300005];
char str[300005];
int fronthead = -1;
int backhead = -1;
int frontempty()
{
	if (fronthead == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int backempty()
{
	if (backhead == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void frontpush(char* frontstack, char str)
{
	frontstack[++fronthead] = str;
}
void backpush(char* backstack, char str)
{
	backstack[++backhead] = str;
}
char frontpop(char* frontstack)
{
	return frontstack[fronthead--];
}
char backpop(char* backstack)
{
	return backstack[backhead--];
}
char target1[30];
char command[30005];
char result[300005];
int resulthead = -1;
int backheaddown = 0;
void resultpush(char* result, char str)
{
	result[++resulthead] = str;
}
char backpopfront(char* backstack)
{
	return backstack[backheaddown++];
}
int frontheaddown = 0;
char frontpopfront(char* frontstack)
{
	return frontstack[frontheaddown++];
}
int main(void)
{
	int result1 = 0;
	scanf("%s", target);
	scanf("%s", str);
	int num = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf(" %c", &command[i]);
	}
	int num1 = strlen(str);
	int num2 = strlen(target);
	for (int i = 0; i < num2; i++)
	{
		target1[i] = target[num2 - i - 1];
	}
	int start = 0;
	int end = num1 - 1;
	int result2 = 0;
	for (int j = 0; j < num; j++)
	{
		if (command[j] == 'L')
		{
			int temp = 0;
			while (temp == 0)
			{
				if (start <= end)
				{
					frontpush(frontstack, str[start]);
					if (fronthead + 1 >= num2)
					{
						int index = fronthead;
						int count = 0;
						for (int i = num2 - 1; i >= 0; i--)
						{
							if (frontstack[index] != target[i])
							{
								count++;
								break;
							}
							else
							{
								index--;
							}
						}
						if (count == 0)
						{
							for (int i = 0; i < num2; i++)
							{
								frontpop(frontstack);
							}
							result2++;
							temp++;
						}
					}
					start++;
				}
				else
				{
					if (backempty() == 0)
					{
						while (backempty() == 0)
						{
							frontpush(frontstack, backpop(backstack));
							if (fronthead + 1 >= num2)
							{
								int index = fronthead;
								int count = 0;
								for (int i = num2 - 1; i >= 0; i--)
								{
									if (frontstack[index] != target[i])
									{
										count++;
										break;
									}
									else
									{
										index--;
									}
								}
								if (count == 0)
								{
									for (int i = 0; i < num2; i++)
									{
										frontpop(frontstack);
									}
									result2++;
									temp++;
									break;
								}
							}
						}
					}
					else
					{
						printf("%d\n", result2);
						if (frontempty() == 0)
						{
							for (int i = 0; i <= fronthead; i++)
							{
								printf("%c", frontstack[i]);
							}
						}
						if (start < end)
						{
							for (int i = start; i <= end; i++)
							{
								printf("%c", str[i]);
							}
						}
						if (backempty() == 0)
						{
							for (int i = backhead; i >= 0; i--)
							{
								printf("%c", backstack[i]);
							}
						}
						printf("\nPerfect!");
						return 0;
					}
				}
			}
		}
		else if (command[j] == 'R')
		{
			int temp = 0;
			while (temp == 0)
			{
				if (start <= end)
				{
					backpush(backstack, str[end]);
					if (backhead + 1 >= num2)
					{
						int index = backhead;
						int count = 0;
						for (int i = num2 - 1; i >= 0; i--)
						{
							if (backstack[index] != target1[i])
							{
								count++;
								break;
							}
							else
							{
								index--;
							}
						}
						if (count == 0)
						{
							for (int i = 0; i < num2; i++)
							{
								backpop(backstack);
							}
							result2++;
							temp++;
						}
					}
					end--;
				}
				else
				{
					if (frontempty() == 0)
					{
						while (frontempty() == 0)
						{
							backpush(backstack, frontpop(frontstack));
							if (backhead + 1 >= num2)
							{
								int index = backhead;
								int count = 0;
								for (int i = num2 - 1; i >= 0; i--)
								{
									if (backstack[index] != target1[i])
									{
										count++;
										break;
									}
									else
									{
										index--;
									}
								}
								if (count == 0)
								{
									for (int i = 0; i < num2; i++)
									{
										backpop(backstack);
									}
									result2++;
									temp++;
									break;
								}
							}
						}
					}
					else
					{
						printf("%d\n", result2);
						if (frontempty() == 0)
						{
							for (int i = 0; i <= fronthead; i++)
							{
								printf("%c", frontstack[i]);
							}
						}
						if (start < end)
						{
							for (int i = start; i <= end; i++)
							{
								printf("%c", str[i]);
							}
						}
						if (backempty() == 0)
						{
							for (int i = backhead; i >= 0; i--)
							{
								printf("%c", backstack[i]);
							}
						}
						printf("\nPerfect!");
						return 0;
					}
				}
			}
		}	
	}

	if (frontheaddown != fronthead + 1)
	{
		while (frontheaddown != fronthead + 1)
		{
			resultpush(result, frontpopfront(frontstack));
			if (resulthead + 1 >= num2)
			{
				int index = resulthead;
				int count = 0;
				for (int i = num2 - 1; i >= 0; i--)
				{
					if (target[i] != result[index])
					{
						count++;
						break;
					}
					else
					{
						index--;
					}
				}
				if (count == 0)
				{
					result1++;
				}
			}
		}
	}
	if (start <= end)
	{
		for (int i = start; i <= end; i++)
		{
			resultpush(result, str[i]);
			if (resulthead + 1 >= num2)
			{
				int index = resulthead;
				int count = 0;
				for (int i = num2 - 1; i >= 0; i--)
				{
					if (target[i] != result[index])
					{
						count++;
						break;
					}
					else
					{
						index--;
					}
				}
				if (count == 0)
				{
					result1++;
				}
			}
		}
	}
	if (backempty() == 0)
	{
		while (backempty() == 0)
		{
			resultpush(result, backpop(backstack));
			if (resulthead + 1 >= num2)
			{
				int index = resulthead;
				int count = 0;
				for (int i = num2 - 1; i >= 0; i--)
				{
					if (target[i] != result[index])
					{
						count++;
						break;
					}
					else
					{
						index--;
					}
				}
				if (count == 0)
				{
					result1++;
				}
			}
		}
	}
	if (result1 == 0)
	{
		printf("%d\n", result2);
		printf("%s\n", result);
		printf("Perfect!");
	}
	else
	{
		printf("%d\n", result2);
		printf("%s\n", result);
		printf("You Lose!");
	}
}