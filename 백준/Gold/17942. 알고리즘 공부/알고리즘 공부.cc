#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll>tp;
typedef tuple<pll, string, ll>pllsl;
ll n = 0, m = 0, k = 0;
bool visited[100001];
vector<pll>graph[100001];
ll dp[100001];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    priority_queue<pll, vector<pll>, greater<pll>>pq;
    for (int i = 0; i < n; i++) {
        ll num = 0;
        cin >> num;
        pq.push({ num, i });
        dp[i] = num;
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        ll a = 0, b = 0, c = 0;
        cin >> a >> b >> c;
        graph[a - 1].push_back({ b - 1, c });
    }
    ll count = 0;
    ll result = 0;
    while (count < m) {
        while (!pq.empty() && visited[pq.top().second]) {
            pq.pop();
        }
        pll temp = pq.top();
        pq.pop();
        result = max(result, temp.first);
        visited[temp.second] = true;
        for (auto& i : graph[temp.second]) {
            if (!visited[i.first]) {
                dp[i.first] -= i.second;
                pq.push({ dp[i.first], i.first });
            }
        }
        count++;
    }
    cout << result;
    return 0;
}