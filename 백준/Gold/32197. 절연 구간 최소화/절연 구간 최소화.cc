#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0;
ll s = 0, e = 0;
bool visited[100001];
struct info {
    ll end;
    ll count;
    ll status;
    bool operator()(const info& a, const info& b) {
        return a.count > b.count;
    }
};
vector<info>graph[100001];
priority_queue<info, vector<info>, info>pq;
void bfs(ll start) {
    visited[start] = true;
    pq.push({start, 0, -1});
    while (!pq.empty()) {
        info temp = pq.top();
        pq.pop();
        //cout << temp.end << ' ' << temp.status << '\n';
        if (temp.end == e) {
            cout << temp.count - 1;
            return;
        }
        visited[temp.end] = true;
        for (auto& i : graph[temp.end]) {
            if (!visited[i.end]) {
                if (temp.status != i.status) {
                    pq.push({i.end, temp.count + 1, i.status});
                }
                else {
                    pq.push({i.end, temp.count, i.status});
                }
                //visited[i.end] = true;
            }
        }
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll start = 0, end = 0, weight = 0;
        cin >> start >> end >> weight;
        graph[start].push_back({end, 0, weight});
        graph[end].push_back({start, 0, weight});
    }
    cin >> s >> e;
    bfs(s);
    return 0;
}