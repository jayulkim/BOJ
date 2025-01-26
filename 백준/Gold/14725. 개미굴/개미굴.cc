#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll>tp;
ll n = 0, m = 0, k = 0;
vector<string>s[1001];
map<string, pll>Map;
vector<pll>graph[1001][16];
vector<pll>start;
bool visited[1001][16];
bool compare(const pll& a, const pll& b) {
    return s[a.first][a.second] < s[b.first][b.second];
}
void dfs(ll y, ll x, ll depth) {
    for (int i = 0; i < depth; i++) {
        cout << "--";
    }
    cout << s[y][x] << '\n';
    visited[y][x] = true;
    for (auto& i : graph[y][x]) {
        if (!visited[i.first][i.second]) {
            dfs(i.first, i.second, depth + 1);
        }
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll num = 0;
        cin >> num;
        string temp = "";
        for (int j = 0; j < num; j++) {
            string str = "";
            cin >> str;
            s[i].push_back(str);
        }
        pll idx = { i, 0 };
        ll x = -1;
        bool find = false;
        for (int j = 0; j < num; j++) {
            temp += s[i][j];
            if (Map.find(temp) == Map.end()) {
                break;
            }
            else {
                find = true;
                idx = Map[temp];
                x = j;
            }
        }
        if (x != -1) {
            graph[idx.first][idx.second].push_back({ i, x + 1 });
            for (int j = 0; j <= x; j++) {
                visited[i][j] = true;
            }
            sort(graph[idx.first][idx.second].begin(), graph[idx.first][idx.second].end(), compare);
        }
        else {
            start.push_back({ i, 0 });
        }
        for (int j = x + 1; j < num - 1; j++) {
            graph[i][j].push_back({ i, j + 1 });
            sort(graph[i][j].begin(), graph[i][j].end(), compare);
        }
        sort(graph[i][num - 1].begin(), graph[i][num - 1].end(), compare);
        temp = "";
        for (int j = 0; j < num; j++) {
            temp += s[i][j];
            if (Map.find(temp) == Map.end()) {
                Map[temp] = { i, j };
            }
        }
    }
    sort(start.begin(), start.end(), compare);
    for (auto& i : start) {
        for (int j = 0; j < s[i.first].size(); j++) {
            if (!visited[i.first][j]) {
                dfs(i.first, j, j);
                break;
            }
        }
    }
    return 0;
}