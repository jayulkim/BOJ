#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[10000005] = { 0, };
long long int prime[1000005] = { 0, };

int up[10000005] = { 0, }; 
int down[10000005] = { 0, };

long long int stack[10000005] = { 0, }; // 소인수 분해 과정에서 3200보다 큰 소수 인덱스 바로 찾아가기 위한 스택
int head = -1;
int empty()
{
	if (head == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void push(long long int* stack, long long int num)
{
	stack[++head] = num;
}

int main(void)
{
	for (int i = 2; i * i <= 10000000; i++) // 천만까지의 소수
	{
		if (ary[i] == 0)
		{
			for (int j = i * i; j <= 10000000; j += i)
			{
				ary[j] = 1;
			}
		}
	}
	int index = 0;
	for (long long int i = 2; i <= 3200; i++) // 소인수 분해에 쓸 소수
	{
		if (ary[i] == 0)
		{
			prime[index] = i;
			index++;
		}
	}

	int num1 = 0;
	scanf("%d", &num1);
	long long int resultup = 1; // 분자 결과
	long long int resultdown = 1; // 분모 결과
	for (int i = 0; i < num1; i++)
	{
		long long int upnumber = 0;
		long long int downnumber = 0;
		scanf("%lld %lld", &upnumber, &downnumber);
		upnumber = downnumber - upnumber; 
		int upindex = 0;
		int downindex = 0;
		while (upnumber > 1)
		{
			if (upnumber % prime[upindex] == 0) // 분자 소인수 분해
			{
				up[prime[upindex]]++; // 그 소수 인덱스를 +1
				upnumber /= prime[upindex];
			}
			else
			{
				upindex++;
			}
			if (prime[upindex] == 0) // 나누다가 3200보다 큰 소수가 나오면
			{
				if (down[upnumber] == 0 && up[upnumber] == 0) // 등장한 적이 없으면
				{
					push(stack, upnumber); // 스택에 저장
				}
				up[upnumber]++; // 그 소수 인덱스를 + 1
				break;
			}
		}
		while (downnumber > 1)
		{
			if (downnumber % prime[downindex] == 0) // 분모 소인수 분해
			{
				down[prime[downindex]]++; // 그 소수 인덱스를 +1
				downnumber /= prime[downindex];
			}
			else
			{
				downindex++;
			}
			if (prime[downindex] == 0)// 나누다가 3200보다 큰 소수가 나오면
			{
				if (down[downnumber] == 0 && up[downnumber] == 0) // 등장한 적이 없으면
				{
					push(stack, downnumber);// 스택에 저장
				}
				down[downnumber]++;// 그 소수 인덱스를 + 1
				break;
			}
		}
	}

	for (int i = 0; i < index; i++) // 3200이하의 소수가 분모 분자에 각각 몇개인지 탐색
	{
		if (up[prime[i]] != 0 || down[prime[i]] != 0) // 분자 또는 분모에 그 수가 등장했으면
		{// 개수 차이만큼 제곱해서 곱하기
			if (up[prime[i]] > down[prime[i]])
			{
				for (int j = 0; j < up[prime[i]] - down[prime[i]]; j++)
				{
					resultup *= (prime[i] % 1000000007); 
					resultup %= 1000000007; // 모듈러 연산
				}
			}
			else if (up[prime[i]] < down[prime[i]])
			{
				for (int j = 0; j < down[prime[i]] - up[prime[i]]; j++)
				{
					resultdown *= (prime[i] % 1000000007);
					resultdown %= 1000000007;// 모듈러 연산
				}
			}
		}
	}
	if (empty() == 0) // 3200보다 큰 소수가 있으면
	{
		for (int i = 0; i <= head; i++)
		{
			if (up[stack[i]] > down[stack[i]]) // 분자 또는 분모에 등장한 소수 탐색
			{// 개수 차이만큼 제곱해서 곱하기
				for (int j = 0; j < up[stack[i]] - down[stack[i]]; j++)
				{
					resultup *= (stack[i] % 1000000007);
					resultup %= 1000000007;// 모듈러 연산
				}
			}
			else if (up[stack[i]] < down[stack[i]])
			{
				for (int j = 0; j < down[stack[i]] - up[stack[i]]; j++)
				{
					resultdown *= (stack[i] % 1000000007);
					resultdown %= 1000000007;// 모듈러 연산
				}
			}
		}
	}
	printf("%lld %lld", resultup % 1000000007, resultdown % 1000000007);
}