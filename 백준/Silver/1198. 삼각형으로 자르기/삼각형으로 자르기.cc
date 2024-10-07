#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<pair<double, double>>v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first >> v[i].second;
	}
	double result = 0;
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i; j < n - 1; j++)
		{
			for (int k = j; k < n; k++)
			{
				double num1 = sqrt((v[i].first - v[j].first) * (v[i].first - v[j].first) + (v[i].second - v[j].second) * (v[i].second - v[j].second));
				double num2 = sqrt((v[k].first - v[j].first) * (v[k].first - v[j].first) + (v[k].second - v[j].second) * (v[k].second - v[j].second));
				double num3 = sqrt((v[i].first - v[k].first) * (v[i].first - v[k].first) + (v[i].second - v[k].second) * (v[i].second - v[k].second));
				double s = (num1 + num2 + num3) / 2;
				result = max(result, sqrt(s * (s - num1) * (s - num2) * (s - num3)));
			}
		}
	}
	printf("%.30lf", result);
	return 0;
}