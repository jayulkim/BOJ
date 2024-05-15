#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int n = 0;
	cin >> n;
	int num1 = 0, num2 = 0, num3 = 0;
	cin >> num1 >> num2 >> num3;
	int premax1 = num1;
	int premax2 = num2;
	int premax3 = num3;
	int premin1 = num1;
	int premin2 = num2;
	int premin3 = num3;
	for (int i = 1; i < n; i++)
	{
		cin >> num1 >> num2 >> num3;
		int pre1 = premax1;
		int pre2 = premax2;
		int pre3 = premax3;
		int pre11 = premin1;
		int pre22 = premin2;
		int pre33 = premin3;
		premax1 = max(pre1, pre2) + num1;
		premax2 = max(max(pre1, pre2), pre3) + num2;
		premax3 = max(pre3, pre2) + num3;
		premin1 = min(pre11, pre22) + num1;
		premin2 = min(min(pre11, pre22), pre33) + num2;
		premin3 = min(pre22, pre33) + num3;
	}
	cout << max(max(premax1, premax2), premax3) << ' ' << min(min(premin1, premin2), premin3);
}