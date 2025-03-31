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
ll visited[100001];
bool finished[100001];
map<ll, ll>Map;
vector<ll>graph[100001];
vector<ll>s;
ll Mapid = 0;
bool visitedid[100001];
bool degree[100001];
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
            Map[temp] = Mapid;
            finished[temp] = true;
            if (temp == start) {
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
        ll d = Map[temp];
        visitedid[temp] = true;
        for (auto& i : graph[temp]) {
            if (Map[i] != d) {
                degree[Map[i]] = true;
            }
            if (!visitedid[i]) {
                visitedid[i] = true;
                q.push(i);
            }
        }
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll num = 0;
    cin >> num;
    while (num--) {
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            ll a = 0, b = 0;
            cin >> a >> b;
            graph[a].push_back(b);
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        for (int i = 0; i < n; i++) {
            if (!visitedid[i]) {
                sccbfs(i);
            }
        }
        vector<ll>result;
        ll count = 0;
        ll idx = -1;
        for (int i = 1; i <= Mapid; i++) {
            if (!degree[i]) {
                count++;
                idx = i;
            }
        }
        if (count != 1) {
            cout << "Confused" << '\n';
        }
        else {
            for (auto& i : Map) {
                if (i.second == idx) {
                    result.push_back(i.first);
                }
            }
            sort(result.begin(), result.end());
            for (auto& i : result) {
                cout << i << '\n';
            }
        }
        cout << '\n';
        memset(degree, false, sizeof(degree));
        memset(visitedid, false, sizeof(visitedid));
        Mapid = 0;
        id = 0;
        map<ll, ll>().swap(Map);
        memset(finished, false, sizeof(finished));
        memset(visited, 0, sizeof(visited));
        vector<ll>().swap(s);
        for (int i = 0; i < n; i++) {
            vector<ll>().swap(graph[i]);
        }
    }
    return 0;
}