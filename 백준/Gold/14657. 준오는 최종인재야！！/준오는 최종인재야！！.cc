#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define len(str) str.length()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<string, char, ll> scl;
typedef tuple<ll, ll, ll, ll> llll;
typedef tuple<ll, ll, ll, ll, ll> lllll;
typedef tuple<ll, ll, vector<ll>> llv;
typedef tuple<char, ll, ll> cll;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
typedef pair<ll, string> pls;
typedef pair<ll, char> plc;
typedef pair<char, ll> pcl;
typedef pair<ll, vector<ll>> plv;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<vector<pll>>graph(n + 1);
    for (int i = 0; i < n - 1; i++) {
        ll a = 0, b = 0, c = 0;
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }
    queue<lll>q;
    q.push({ 1, 1, 0 });
    vector<ll>vi(n + 1, 0);
    vector<ll>v(n + 1, 0);
    ll Max = 1;
    while (!q.empty()) {
        auto [a, b, c] = q.front();
        q.pop();
        vi[a] = b;
        v[a] = c;
        for (auto& i : graph[a]) {
            if (!vi[i.first]) {
                vi[i.first] = b + 1;
                v[i.first] = c + i.second;
                q.push({ i.first, b + 1, c + i.second });
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        Max = max(Max, vi[i]);
    }
    ll Min = LLONG_MAX;
    for (int i = 1; i <= n; i++) {
        if (Max == vi[i]) {
            Min = min(Min, v[i]);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (Max == vi[i] && Min == v[i]) {
            q.push({ i, 1, 0 });
            break;
        }
    }
    vector<ll>(n + 1, 0).swap(v);
    vector<ll>(n + 1, 0).swap(vi);
    Max = 1;
    while (!q.empty()) {
        auto [a, b, c] = q.front();
        q.pop();
        v[a] = c;
        vi[a] = b;
        for (auto& i : graph[a]) {
            if (!vi[i.first]) {
                vi[i.first] = b + 1;
                v[i.first] = c + i.second;
                q.push({ i.first, b + 1, c + i.second });
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        Max = max(Max, vi[i]);
    }
    ll result = LLONG_MAX;
    for (int i = 1; i <= n; i++) {
        if (Max == vi[i]) {
            result = min(result, (v[i] + m - 1) / m);
        }
    }
    cout << result;
    return 0;
}