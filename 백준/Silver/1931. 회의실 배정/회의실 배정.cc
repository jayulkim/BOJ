#include <bits/stdc++.h>
using namespace std;
struct info
{
	int start;
	int end;
};
bool compare(const info& num1, const info& num2)
{
	if (num1.end == num2.end)
	{
		return num1.start < num2.start;
	}
	return num1.end < num2.end;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<info>v;
	for (int i = 0; i < n; i++)
	{
		int first = 0, second = 0;
		cin >> first >> second;
		v.push_back({ first, second });
	}
	sort(v.begin(), v.end(), compare);
	int end = v[0].end;
	int result = 1;
	int idx = 1;
	while (idx < n)
	{
		int count = 0;
		for (int i = idx; i < n; i++)
		{
			if (v[i].start >= end)
			{
				end = v[i].end;
				idx = i + 1;
				count++;
				result++;
				break;
			}
		}
		if (count == 0)
		{
			break;
		}
	}
	cout << result;
}