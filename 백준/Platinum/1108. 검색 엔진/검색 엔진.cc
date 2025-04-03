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
vector<ll>topograph[1251];
ll degree[1251];
vector<ll>s;
ll dp[1251];
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
        while (1) {
            ll temp = s.back();
            s.pop_back();
            finished[temp] = true;
            idMap[temp] = idid;
            if (start == temp) {
                break;
            }
        }
    }
    return parent;
}
void toposort() {
    queue<ll>q;
    for (int i = 1; i <= idx; i++) {
        dp[i] = 1;
        if (!degree[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        ll temp = q.front();
        q.pop();
        ll d = idMap[temp];
        for (auto& i : topograph[temp]) {
            if (d != idMap[i]) {
                dp[i] += dp[temp];
            }
            if (--degree[i] == 0) {
                q.push(i);
            }
        }
    }
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
        ll temp = idMap[i];
        for (auto& j : graph[i]) {
            if (temp != idMap[j]) {
                topograph[i].push_back(j);
                degree[j]++;
            }
        }
    }
    toposort();
    string str = "";
    cin >> str;
    cout << dp[Map[str]];
    return 0;
}