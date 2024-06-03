#include <bits/stdc++.h>
using namespace std;
struct info
{
	int temp;
	int start;
	int end;
};
bool compare(const info& num1, const info& num2)
{
	return num1.temp < num2.temp;
}
bool ary[1001];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<int>v(k);
	vector<info>Log(m);
	for (int i = 0; i < k; i++)
	{
		cin >> v[i];
        ary[v[i]] = true;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> Log[i].temp >> Log[i].start >> Log[i].end;
	}
	sort(Log.begin(), Log.end(), compare);
	for (int j = 0; j < k; j++)
	{
		vector<bool>virus(n + 1, false);
		virus[v[j]] = true;
		for (int i = 0; i < m; i++)
		{
			if (virus[Log[i].start] == true)
			{
				virus[Log[i].end] = true;
			}
		}
		int count = 0;
		for (int i = 1; i <= n; i++)
		{
			if (virus[i] && ary[i])
			{
				count++;
			}
            else if (virus[i] && !ary[i])
            {
               count = 0;
               break;
            }
		}
		if (count == k)
		{
			cout << v[j];
			return 0;
		}
	}
	return 0;
}