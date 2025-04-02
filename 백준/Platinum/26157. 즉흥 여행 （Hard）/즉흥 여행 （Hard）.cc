#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
ll id = 0;
ll visited[200001];
bool finished[200001];
vector<ll>s;
map<ll, ll>Map;
ll Mapid = 0;
vector<ll>graph[200001];
bool visitedid[200001];
ll degree[200001];
vector<ll>topograph[200001];
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
        Mapid++;
        while (1) {
            ll temp = s.back();
            s.pop_back();
            finished[temp] = true;
            Map[temp] = Mapid;
            if (start == temp) {
                break;
            }
        }
    }
    return parent;
}
void sccbfs(ll start) {
    visitedid[start] = true;
    queue<ll>q;
    q.push(start);
    while (!q.empty()) {
        ll temp = q.front();
        q.pop();
        visitedid[temp] = true;
        ll d = Map[temp];
        for (auto& i : graph[temp]) {
            if (d != Map[i]) {
                degree[Map[i]]++;
                topograph[d].push_back(Map[i]);
            }
            if (!visitedid[i]) {
                visitedid[i] = true;
                q.push(i);
            }
        }
    }
}
void toposort() {
    queue<ll>q;
    ll idx = 0;
    for (int i = 1; i <= Mapid; i++) {
        if (!degree[i]) {
            q.push(i);
            idx = i;
        }
    }
    if (q.size() != 1) {
        cout << 0;
        return;
    }
    while (!q.empty()) {
        ll temp = q.front();
        q.pop();
        ll count = 0;
        for (auto& i : topograph[temp]) {
            if (--degree[i] == 0) {
                q.push(i);
                count++;
            }
        }
        if (count != 1 && q.size()) {
            cout << 0;
            return;
        }
    }
    vector<ll>result;
    for (auto& i : Map) {
        if (i.second == idx) {
            result.push_back(i.first);
        }
    }
    sort(result.begin(), result.end());
    cout << result.size() << '\n';
    for (auto& i : result) {
        cout << i << ' ';
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll a = 0, b = 0;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    bool find = false;
    for (int i = 1; i <= n; i++) {
        if (!visitedid[i]) {
            sccbfs(i);
        }
    }
    toposort();
    return 0;   
}