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
    ll num = 0;
    cin >> num;
    while (num--) {
        cin >> n >> m;
        vector<vector<ll>>graph(n + 1);
        for (int i = 0; i < m; i++) {
            ll a = 0, b = 0;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }       
        bool find = false;
        queue<pll>q;
        vector<ll>vi(n + 1, -1);
        for (int i = 1; i <= n; i++) {
            if (vi[i] == -1) {
                q.push({i, 0});
                while (!q.empty()) {
                    auto [a, b] = q.front();
                    q.pop();
                    vi[a] = b;
                    for (auto& i : graph[a]) {
                        if (vi[i] == -1) {
                            vi[i] = (b + 1) % 2;
                            q.push({ i, (b + 1) % 2 });
                        }
                        else if (vi[i] == b) {
                            find = true;
                            break;
                        }
                    }
                    if (find) {
                        break;
                    }
                }
                if (find) {
                    break;
                }
            }
        }
        if (find) {
            cout << "impossible\n";
        }
        else {
            cout << "possible\n";
        }
    }
    return 0;
}