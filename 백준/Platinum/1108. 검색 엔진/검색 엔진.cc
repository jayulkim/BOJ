#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
map<string, ll>Map;
ll idx = 0;
ll id = 0;
ll idid = 0;
ll visited[1251];
bool finished[1251];
map<ll, ll>idMap;
vector<ll>graph[1251];
vector<ll>s;
ll dp[1251];
vector<vector<ll>>scc;
ll dfs(ll start) {
    visited[start] = ++id;
    ll parent = visited[start];
    s.push_back(start);
    for (auto& i : graph[start]) {
        if (!visited[i]) {
            parent = min(parent, dfs(i));
        }
        else if (!finished[i]) {
            parent = min(parent, visited[i]);
        }
    }
    if (parent == visited[start]) {
        idid++;
        vector<ll>v;
        while (1) {
            ll temp = s.back();
            s.pop_back();
            finished[temp] = true;
            idMap[temp] = idid;
            v.push_back(temp);
            if (start == temp) {
                break;
            }
        }
        scc.push_back(v);
    }
    return parent;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str = "";
        cin >> str;
        if (!Map[str]) {
            Map[str] = ++idx;
        }
        ll a = 0;
        cin >> a;
        for (int j = 0; j < a; j++) {
            string s = "";
            cin >> s;
            if (!Map[s]) {
                Map[s] = ++idx;
            }
            graph[Map[s]].push_back(Map[str]);
        }
    }
    for (int i = 1; i <= idx; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    for (int i = 1; i <= idx; i++) {
        dp[i] = 1;
    }
    for (int i = scc.size() - 1; i >= 0; i--) {
        for (auto& j : scc[i]) {
            ll temp = idMap[j];
            for (auto& k : graph[j]) {
                if (temp != idMap[k]) {
                    dp[k] += dp[j];
                }
            }
        }
    }
    string str = "";
    cin >> str;
    cout << dp[Map[str]];
    return 0;
}