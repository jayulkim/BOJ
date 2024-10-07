#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int ary[3][3] = { 0, };
	int player1 = 0;
	int player2 = 0;

	scanf("%d", &player1);
	if (player1 == 1)
	{
		player2 = 2;
	}
	if (player1 == 2)
	{
		player2 = 1;
	}

	while (1)
	{
		int num1 = 0;
		int num2 = 0;
		int num3 = 0;
		int num4 = 0;
		scanf("%d %d", &num1, &num2);
		
		if (ary[num1 - 1][num2 - 1] == 0)
		{
			ary[num1 - 1][num2 - 1] = player1;
		}

		
	
		if (ary[0][0] == ary[0][2] && ary[0][0] == ary[0][1] && ary[0][1] == player1)
		{
			printf("%d", player1);
			break;
		}
		else if (ary[1][0] == ary[1][2] && ary[1][0] == ary[1][1] && ary[1][1] == player1)
		{
			printf("%d", player1);
			break;
		}
		else if (ary[2][0] == ary[2][2] && ary[2][0] == ary[2][1] && ary[2][1] == player1)
		{
			printf("%d", player1);
			break;
		}
		else if (ary[0][0] == ary[1][0] && ary[0][0] == ary[2][0] && ary[2][0] == player1)
		{
			printf("%d", player1);
			break;
		}
		else if (ary[0][1] == ary[1][1] && ary[0][1] == ary[2][1] && ary[2][1] == player1)
		{
			printf("%d", player1);
			break;
		}
		else if (ary[0][2] == ary[1][2] && ary[0][2] == ary[2][2] && ary[2][2] == player1)
		{
			printf("%d", player1);
			break;
		}
		else if (ary[0][0] == ary[1][1] && ary[0][0] == ary[2][2] && ary[2][2] == player1)
		{
			printf("%d", player1);
			break;
		}
		else if (ary[0][2] == ary[1][1] && ary[0][2] == ary[2][0] && ary[2][0] == player1)
		{
			printf("%d", player1);
			break;
		}
		else
		{
			if (ary[0][0] != 0 && ary[0][1] != 0 && ary[0][2] != 0 && ary[1][0] != 0 && ary[1][1] != 0 && ary[1][2] != 0 && ary[2][0] != 0 && ary[2][1] != 0 && ary[2][2] != 0)
			{
				printf("0");
				break;
			}
		}
		
		scanf("%d %d", &num3, &num4);
		if (ary[num3 - 1][num4 - 1] == 0)
		{
			ary[num3 - 1][num4 - 1] = player2;
		}
		
		if (ary[0][0] == ary[0][2] && ary[0][0] == ary[0][1] && ary[0][1] == player2)
		{
			printf("%d", player2);
			break;
		}
		else if (ary[1][0] == ary[1][2] && ary[1][0] == ary[1][1] && ary[1][1] == player2)
		{
			printf("%d", player2);
			break;
		}
		else if (ary[2][0] == ary[2][2] && ary[2][0] == ary[2][1] && ary[2][1] == player2)
		{
			printf("%d", player2);
			break;
		}
		else if (ary[0][0] == ary[1][0] && ary[0][0] == ary[2][0] && ary[2][0] == player2)
		{
			printf("%d", player2);
			break;
		}
		else if (ary[0][1] == ary[1][1] && ary[0][1] == ary[2][1] && ary[2][1] == player2)
		{
			printf("%d", player2);
			break;
		}
		else if (ary[0][2] == ary[1][2] && ary[0][2] == ary[2][2] && ary[2][2] == player2)
		{
			printf("%d", player2);
			break;
		}
		else if (ary[0][0] == ary[1][1] && ary[0][0] == ary[2][2] && ary[2][2] == player2)
		{
			printf("%d", player2);
			break;
		}
		else if (ary[0][2] == ary[1][1] && ary[0][2] == ary[2][0] && ary[2][0] == player2)
		{
			printf("%d", player2);
			break;
		}
		else
		{
			if (ary[0][0] != 0 && ary[0][1] != 0 && ary[0][2] != 0 && ary[1][0] != 0 && ary[1][1] != 0 && ary[1][2] != 0 && ary[2][0] != 0 && ary[2][1] != 0 && ary[2][2] != 0)
			{
				printf("0");
				break;
			}
		}
		
	}
	

}