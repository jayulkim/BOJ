#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll>tp;
typedef tuple<pll, string, ll>pllsl;
ll n = 0, m = 0, k = 0;
vector<pll>v;
vector<ll>result;
bool visited[21];
ll temp = -1;
void dfs() {
    if (result.size() == m) {
        ll a = 0, b = 0;
        for (auto& i : result) {
            a += v[i].first;
            b += v[i].second;
        }
        if (a <= k && k <= b) {
            vector<ll>vv(n, 0);
            vector<bool>visited(n, false);
            for (auto& i : result) {
                vv[i] = v[i].first;
                visited[i] = true;
            }
            ll need = k - a;
            for (int i = 0; i < n; i++) {
                if (visited[i]) {
                    if (need >= v[i].second - v[i].first) {
                        vv[i] = v[i].second;
                        need -= v[i].second - v[i].first;
                    }
                    else {
                        vv[i] += need;
                        break;
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                if (visited[i] && !vv[i]) {
                    for (int j = 0; j < i; j++) {
                        if (visited[j] && vv[j] > 1) {
                            vv[j]--;
                            vv[i] = 1;
                            break;
                        }
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                cout << vv[i] << ' ';
            }
            exit(0);
        }
        return;
    }
    for (int i = temp + 1; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            result.push_back(i);
            temp = i;
            dfs();
            result.pop_back();
            visited[i] = false;
        }
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        ll a = 0, b = 0;
        cin >> a >> b;
        v.push_back({ a, b });
    }
    if (n < m) {
        cout << -1;
        return 0;
    }
    dfs();
    cout << -1;
    return 0;
}