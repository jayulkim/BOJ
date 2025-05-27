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
    cin >> n;
    string str = "";
    cin >> str;
    vector<vector<ll>>graph(n + 1);
    for (int i = 0; i < n - 1; i++) {
        ll a = 0, b = 0;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    queue<pll>q;
    vector<bool>visited(n + 1, false);
    q.push({ 1, 1 });
    vector<ll>step(n + 1);
    while (!q.empty()) {
        pll temp = q.front();
        q.pop();
        visited[temp.first] = true;
        step[temp.first] = temp.second;
        for (auto& i : graph[temp.first]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push({ i, temp.second + 1 });
            }
        }
    }
    queue<ll>qq;
    qq.push(1);
    string result = "";
    result += str[0];
    vector<bool>(n + 1, false).swap(visited);
    visited[1] = true;
    while (!qq.empty()) {
        vector<ll>v;
        while (!qq.empty()) {
            ll temp = qq.front();
            qq.pop();
            for (auto& i : graph[temp]) {
                if (!visited[i] && step[i] > step[temp]) {
                    v.push_back(i);
                }
            }
        }
        ll Max = 0;
        for (auto& i : v) {
            Max = max(Max, (ll)str[i - 1]);
        }
        for (auto& i : v) {
            if (str[i - 1] == Max) {
                qq.push(i);
                visited[i] = true;
            }
        }
        if (Max) {
            result += Max;
        }
    }
    cout << result;
    return 0;
}