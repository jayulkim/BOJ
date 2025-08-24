#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll num = 0;
    cin >> num;
    while (num--) {
        cin >> n;
        vector<vector<ll>>graph(n + 1);
        for (int i = 0; i < n - 1; i++) {
            ll a = 0, b = 0;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        vector<bool>visited(n + 1, false);
        ll result = 0;
        queue<pll>q;
        q.push({ 0, 0 });
        pll Max = { 0, -1 };
        while (!q.empty()) {
            pll temp = q.front();
            q.pop();
            visited[temp.first] = true;
            Max = max(Max, { temp.second, temp.first });
            for (auto& j : graph[temp.first]) {
                if (!visited[j]) {
                    visited[j] = true;
                    q.push({ j, temp.second + 1 });
                }
            }
        }
        vector<bool>visited1(n + 1, false);
        q.push({ Max.second, 0 });
        while (!q.empty()) {
            pll temp = q.front();
            q.pop();
            visited1[temp.first] = true;
            result = temp.second;
            for (auto& j : graph[temp.first]) {
                if (!visited1[j]) {
                    visited1[j] = true;
                    q.push({ j, temp.second + 1 });
                }
            }
        }
        cout << (result + 1) / 2 << '\n';
    }
    return 0;
}