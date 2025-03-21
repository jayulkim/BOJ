#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
bool visited[201][201][201];
vector<ll>result;
void bfs(ll a, ll b, ll c) {
    visited[a][b][c] = true;
    queue<lll>q;
    q.push({ a, b, c });
    while (!q.empty()) {
        auto [a, b, c] = q.front();
        q.pop();
        if (!a) {
            result.push_back(c);
        }
        visited[a][b][c] = true;
        if (!visited[min(n, a + b)][max((ll)0, b - (n - a))][c]) {
            visited[min(n, a + b)][max((ll)0, b - (n - a))][c] = true;
            q.push({ min(n, a + b), max((ll)0, b - (n - a)), c });
        }
        if (!visited[max((ll)0, a - (m - b))][min(m, a + b)][c]) {
            visited[max((ll)0, a - (m - b))][min(m, a + b)][c] = true;
            q.push({ max((ll)0, a - (m - b)), min(m, a + b), c });
        }
        if (!visited[a][max((ll)0, b - (k - c))][min(k, b + c)]) {
            visited[a][max((ll)0, b - (k - c))][min(k, b + c)] = true;
            q.push({ a, max((ll)0, b - (k - c)), min(k, b + c) });
        }
        if (!visited[a][min(m, b + c)][max((ll)0, c - (m - b))]) {
            visited[a][min(m, b + c)][max((ll)0, c - (m - b))] = true;
            q.push({ a, min(m, b + c), max((ll)0, c - (m - b)) });
        }
        if (!visited[max((ll)0, a - (k - c))][b][min(k, a + c)]) {
            visited[max((ll)0, a - (k - c))][b][min(k, a + c)] = true;
            q.push({ max((ll)0, a - (k - c)), b, min(k, a + c) });
        }
        if (!visited[min(n, a + c)][b][max((ll)0, c - (n - a))]) {
            visited[min(n, a + c)][b][max((ll)0, c - (n - a))] = true;
            q.push({ min(n, a + c), b, max((ll)0, c - (n - a)) });
        }
    }
}
int main(void) {
	ios::sync_with_stdio(false);	cin.tie(0);
    cin >> n >> m >> k;
    bfs(0, 0, k);
    sort(result.begin(), result.end());
    for (auto& i : result) {
        cout << i << ' ';
    }
	return 0;
}    