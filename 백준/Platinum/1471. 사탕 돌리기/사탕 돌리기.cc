//폰 코딩
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<vector<ll>>graph(n + 1);
    vector<vector<ll>>topograph(n + 1);
    vector<ll>degree(n + 1, 0);
    vector<ll>s;
    vector<ll>visited(n + 1, 0);
    vector<bool>finished(n + 1, false);
    ll id = 0;
    vector<ll>Map(n + 1);
    vector<ll>v(n + 1, 0);
    ll Mapid = 0;
    for (int i = 0; i < n; i++) {
        ll temp = i + 1;
        ll sum = 0;
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
        graph[i].push_back((i + sum) % n);
    }
    function<ll(ll)> dfs = [&](ll start) -> ll {
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
            ll count = 0;
            Mapid++;
            while (1) {
                ll temp = s.back();
                s.pop_back();
                finished[temp] = true;
                Map[temp] = Mapid;
                count++;
                if (start == temp) {
                    break;
                }
            }
            v[Mapid] = count;
        }
        return parent;
        };
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    for (int i = 0; i < n; i++) {
        for (auto& j : graph[i]) {
            if (Map[i] != Map[j]) {
                topograph[Map[i]].push_back(Map[j]);
                degree[Map[j]]++;
            }
        }
    }
    vector<ll>dp(n + 1, 0);
    queue<ll>q;
    for (int i = 1; i <= Mapid; i++) {
        if (!degree[i]) {
            q.push(i);
            dp[i] = v[i];
        }
    }
    while (!q.empty()) {
        ll temp = q.front();
        q.pop();
        for (auto& i : topograph[temp]) {
            if (--degree[i] == 0) {
                q.push(i);
            }
            dp[i] = max(dp[i], dp[temp] + v[i]);
        }
    }
    ll Max = 1;
    for (int i = 1; i <= Mapid; i++) {
        Max = max(Max, dp[i]);
    }
    cout << Max;
    return 0;
}