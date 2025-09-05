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
    cin >> n >> m;
    map<ll, vector<ll>>Map;
    vector<vector<bool>>visited(n + 1, vector<bool>(n + 1, false));
    for (int i = 0; i < m; i++) {
        ll a = 0, b = 0;
        cin >> a >> b;
        visited[a][b] = true;
        Map[b].push_back(a);
        visited[b][a] = true;
    }
    ll result = 0;
    for (auto& i : Map) {
        for (int j = 0; j < i.second.size() - 1; j++) {
            for (int k = j + 1; k < i.second.size(); k++) {
                if (!visited[i.second[j]][i.second[k]]) {
                    result++;
                }
            }
        }
    }
    cout << result;
    return 0;
}