#include <bits/stdc++.h>
using namespace std;
int sumA[1000001];
int aryA[1000001];
int sumC[1000001];
int aryC[1000001];
int sumG[1000001];
int aryG[1000001];
int sumT[1000001];
int aryT[1000001];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0;
	cin >> n >> m;
	string str = "";
	cin >> str;
	for (int i = 0; i < n; i++)
	{
		if (str[i] == 'A')
		{
			aryA[i + 1]++;
		}
		else if (str[i] == 'C')
		{
			aryC[i + 1]++;
		}
		else if (str[i] == 'G')
		{
			aryG[i + 1]++;
		}
		else if (str[i] == 'T')
		{
			aryT[i + 1]++;
		}
	}
	sumA[1] = aryA[1];
	sumC[1] = aryC[1];
	sumG[1] = aryG[1];
	sumT[1] = aryT[1];
	for (int i = 2; i <= n; i++)
	{
		sumA[i] = sumA[i - 1] + aryA[i];
		sumC[i] = sumC[i - 1] + aryC[i];
		sumG[i] = sumG[i - 1] + aryG[i];
		sumT[i] = sumT[i - 1] + aryT[i];
	}
	int A = 0, C = 0, G = 0, T = 0;
	cin >> A >> C >> G >> T;
	int count = 0;
	for (int i = m; i <= n; i++)
	{
		if (sumA[i] - sumA[i - m] >= A && sumC[i] - sumC[i - m] >= C && sumG[i] - sumG[i - m] >= G && sumT[i] - sumT[i - m] >= T)
		{
			count++;
		}
	}
	cout << count;
	return 0;
}