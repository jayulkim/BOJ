//폰 코딩
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
ll id = 0;
ll visited[101];
bool finished[101];
char Map[101][101];
ll cost[101];
vector<ll>s;
ll result = 0;
ll dfs(ll start) {
    visited[start] = ++id;
    ll parent = visited[start];
    s.push_back(start);
    for (int i = 1; i <= n; i++) {
        if (Map[start][i] == '1') {
            if (!visited[i]) {
                parent = min(parent, dfs(i));
            }
            else if (!finished[i]) {
                parent = min(parent, visited[i]);
            }
        }
    }
    if (parent == visited[start]) {
        ll Min = LLONG_MAX;
        while (1) {
            ll temp = s.back();
            s.pop_back();
            Min = min(Min, cost[temp]);
            finished[temp] = true;
            if (start == temp) {
                break;
            }
        }
        result += Min;
    }
    return parent;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> Map[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    cout << result;
    return 0;
}