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
vector<ll>graph[200001];
vector<ll>s;
bool finished[200001];
ll Mapid = 0;
map<ll, ll>Map;
map<ll, ll>idMapa;
map<ll, ll>idMapb;
ll dfs(ll start) {
    visited[start] = ++id;
    s.push_back(start);
    ll parent = visited[start];
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
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll a = 0, b = 0;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    cin >> k;
    vector<ll>a;
    vector<ll>b;
    for (int i = 0; i < k; i++) {
        ll num = 0;
        cin >> num;
        a.push_back(num);
    }
    for (int i = 0; i < k; i++) {
        ll num = 0;
        cin >> num;
        b.push_back(num);
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    for (auto& i : a) {
        idMapa[Map[i]]++;
    }
    for (auto& i : b) {
        idMapb[Map[i]]++;
    }
    if (idMapa == idMapb) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;   
}