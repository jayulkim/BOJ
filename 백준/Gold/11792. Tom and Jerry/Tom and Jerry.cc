#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
int main(void)
{
	int num = 0;
	cin >> num;
	for (int i = 1; i <= num; i++)
	{
		ld num1 = 0, num2 = 0;
		cin >> num1 >> num2;
		cout.precision(30);
		cout << "Case " << i << ": " << (num1 * (ld)3.14159265358979323846264338 / num2) / (ld)2 << '\n';
	}
}