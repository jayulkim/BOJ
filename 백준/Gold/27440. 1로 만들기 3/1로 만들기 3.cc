#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
unordered_set<ll>visited;
int result = 0;
void bfs(ll start)
{
	queue<ll>q1;
	queue<ll>q2;
	q1.push(start);
	visited.insert(start);
	while (1)
	{
		while (!q1.empty())
		{
			ll temp = q1.front();
			q1.pop();
			if (temp == 1)
			{
				cout << result;
				return;
			}
			visited.insert(temp);
			if (temp % 3 == 0 && visited.find(temp / 3) == visited.end())
			{
				q2.push(temp / 3);
				visited.insert(temp / 3);
			}
			if (temp % 2 == 0 && visited.find(temp / 2) == visited.end())
			{
				q2.push(temp / 2);
				visited.insert(temp / 2);
			}
			if (temp - 1 > 0 && visited.find(temp - 1) == visited.end())
			{
				q2.push(temp - 1);
				visited.insert(temp - 1);
			}
		}
		result++;
		while (!q2.empty())
		{
			ll temp = q2.front();
			q2.pop();
			if (temp == 1)
			{
				cout << result;
				return;
			}
			visited.insert(temp);
			if (temp % 3 == 0 && visited.find(temp / 3) == visited.end())
			{
				q1.push(temp / 3);
				visited.insert(temp / 3);
			}
			if (temp % 2 == 0 && visited.find(temp / 2) == visited.end())
			{
				q1.push(temp / 2);
				visited.insert(temp / 2);
			}
			if (temp - 1 > 0 && visited.find(temp - 1) == visited.end())
			{
				q1.push(temp - 1);
				visited.insert(temp - 1);
			}
		}
		result++;
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0;
	cin >> n;
	bfs(n);
}