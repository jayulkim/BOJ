#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll> lll;
typedef tuple<pll, string, ll> pllsl;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin >> n >> m >> k;
    vector<vector<ll>>graph(n + 1);
    vector<map<ll, ll>>Map(n + 1);
    vector<map<ll, ll>>tempMap(n + 1);
    vector<ll>degree(n + 1, 0);
    for (int i = 0; i < m; i++) {
        ll a = 0, b = 0;
        cin >> a >> b;
        graph[a].push_back(b);
        Map[b][a]++;
    }
    bool find = false;
    for (int i = 0; i < k; i++) {
        ll a = 0, b = 0;
        cin >> a >> b;
        if (a == 1) {
            if (tempMap[b].size() == Map[b].size()) {
                degree[b]++;
                for (auto& j : graph[b]) {
                    tempMap[j][b]++;
                }
            }
            else {
                find = true;
            }
        }
        else {
            degree[b]--;
            if (degree[b] < 0) {
                find = true;
            }
            else if (!degree[b]) {
                for (auto& j : graph[b]) {
                    tempMap[j].erase(tempMap[j].find(b));
                }
            }
        }
    }
    if (!find) {
        cout << "King-God-Emperor";
    }
    else {
        cout << "Lier!";
    }
	return 0;
}