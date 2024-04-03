#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int ary[200005] = { 0, };
int Ustack[200005] = { 0, };
int Dstack[200005] = { 0, };
int Pstack[200005] = { 0, };

int Uhead = -1;
int Dhead = -1;
int Phead = -1;

int result[200005] = { 0, };
int ary1[200005] = { 0, };
int ary2[200005] = { 0, };

int compare(const void* num1, const void* num2)
{
	return *(int*)num1 - *(int*)num2;
}

int Uempty()
{
	if (Uhead == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int Dempty()
{
	if (Dhead == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int Pempty()
{
	if (Phead == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void Upush(int* Ustack, int num)
{
	Ustack[++Uhead] = num;
}
void Dpush(int* Dstack, int num)
{
	Dstack[++Dhead] = num;
}
void Ppush(int* Pstack, int num)
{
	Pstack[++Phead] = num;
}

int Utop(int* Ustack)
{
	return Ustack[Uhead];
}

int Dtop(int* Dstack)
{
	return Dstack[Dhead];
}
int Ptop(int* Pstack)
{
	return Pstack[Phead];
}
void Uclear()
{
	Uhead = -1;
}
void Dclear()
{
	Dhead = -1;
}
void Pclear()
{
	Phead = -1;
}

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		int num2 = 0;
		scanf("%d", &num2);
		for (int j = 0; j < num2; j++)
		{
			scanf("%d", &ary[j]);
			ary1[j] = ary[j];
		}
		qsort(ary1, num2, sizeof(int), compare);
		for (int j = 0; j < num2; j++)
		{
			ary2[ary1[j]] = j;
		}
		for (int j = 0; j < num2; j++)
		{
			result[j] = ary2[ary[j]];
		//	printf("%d\n", result[j]);
		}
		int index = 0;
		int count = 0;
		
		while (index < num2)
		{
			if (Uempty() == 1)
			{
				Upush(Ustack, result[index]);
				index++;
			}
			else
			{
				if (Utop(Ustack) == result[index] - 1)
				{
					Upush(Ustack, result[index]);
					index++;
				}
				else
				{
					if (Dempty() == 1)
					{
						Dpush(Dstack, result[index]);
						index++;
					}
					else
					{
						if (Dtop(Dstack) == result[index] - 1)
						{
							Dpush(Dstack, result[index]);
							index++;
						}
						else
						{
							if (Pempty() == 1)
							{
								Ppush(Pstack, result[index]);
								index++;
							}
							else
							{
								if (Ptop(Pstack) == result[index] - 1)
								{
									Ppush(Pstack, result[index]);
									index++;
								}
								else
								{
									if (Ustack[0] == count)
									{
										count = Utop(Ustack) + 1;
										Uclear();
									}
									else
									{
										if (Dstack[0] == count)
										{
											count = Dtop(Dstack) + 1;
											Dclear();
										}
										else
										{
											if (Pstack[0] == count)
											{
												count = Ptop(Pstack) + 1;
												Pclear();
											}
											else
											{
												printf("NO\n");
												break;
											}
										}
									}
								}
							}
						}
					}
					
				}
			}
		}
		if (num2 == index)
		{
			for (int j = 0; j <= Uhead; j++)
			{
			//	printf("%d ", Ustack[j]);
			}
		//	printf("\n");
			for (int j = 0; j <= Dhead; j++)
			{
			//	printf("%d ", Dstack[j]);
			}
			//printf("\n");
			printf("YES\n");
		}
		Uclear();
		Dclear();
		Pclear();
	}
}