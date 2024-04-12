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
int main(void)
{
	scanf("%s", target);
	scanf("%s", str);
	int num1 = strlen(str);
	int num2 = strlen(target);
	for (int i = 0; i < num2; i++)
	{
		target1[i] = target[num2 - i - 1];
	}
	int front = 1;
	int back = 0;
	int start = 0;
	int end = num1 - 1;
	while (1)
	{
		if (front == 1)
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
						front = 0;
						back = 1;
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
								front = 0;
								back = 1;
								break;
							}
						}
					}
				}
				else
				{
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
					return 0;
				}
			}
		}
		else if (back == 1)
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
						front = 1;
						back = 0;
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
								front = 1;
								back = 0;
								break;
							}
						}
					}
				}
				else
				{
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
					return 0;
				}
			}
		}
	}
}