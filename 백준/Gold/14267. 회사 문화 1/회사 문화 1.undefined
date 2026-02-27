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
    vector<vector<ll>>graph(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> k;
        if (k != -1) {
            graph[k].push_back(i);
        }
    }
    vector<ll>vi(n + 1, 0);
    queue<ll>q;
    for (int i = 0; i < m; i++) {
        ll a = 0, b = 0;
        cin >> a >> b;
        vi[a] += b;
    }
    q.push(1);
    while (!q.empty()) {
        ll temp = q.front();
        q.pop();
        for (auto& i : graph[temp]) {
            vi[i] += vi[temp];
            q.push(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << vi[i] << ' ';
    }
    return 0;
}