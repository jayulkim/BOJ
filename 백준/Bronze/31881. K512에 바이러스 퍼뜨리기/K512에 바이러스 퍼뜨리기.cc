#include <bits/stdc++.h>
using namespace std;
bool visited[200001];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, q = 0;
	cin >> n >> q;
	for (int i = 0; i < q; i++)
	{
		int num = 0, number = 0;
		cin >> num;
		if (num == 1)
		{
			cin >> number;
			if (visited[number] == false)
			{
				n--;
				visited[number] = true;
			}
		}
		else if (num == 2)
		{
			cin >> number;
			if (visited[number] == true)
			{
				n++;
				visited[number] = false;
			}
		}
		else if (num == 3)
		{
			cout << n << '\n';
		}
	}
	return 0;
}