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
    while (1) {
        cin >> n;
        if (!n) {
            break;
        }
        vector<bool>Map(31, false);
        vector<vector<ll>>graph(1001);
        vector<bool>finished(1001, false);
        vector<ll>visited(1001, 0);
        ll id = 0;
        vector<ll>stack;
        vector<vector<ll>>scc;
        for (int i = 0; i < n; i++) {
            vector<ll>temp;
            for (int j = 0; j < 5; j++) {
                char c;
                cin >> c;
                Map[c - 'A'] = true;
                temp.push_back(c - 'A');
            }
            char c;
            cin >> c;
            Map[c - 'A'] = true;
            for (auto& j : temp) {
                graph[j].push_back(c - 'A');
            }
        }
        function<ll(ll)> dfs = [&](ll start) -> ll {
            visited[start] = ++id;
            stack.push_back(start);
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
                vector<ll>v;
                while (1) {
                    ll temp = stack.back();
                    stack.pop_back();
                    finished[temp] = true;
                    v.push_back(temp);
                    if (start == temp) {
                        break;
                    }
                }
                scc.push_back(v);
            }
            return parent;
            };
        for (int i = 0; i < 26; i++) {
            if (!visited[i] && Map[i]) {
                dfs(i);
            }
        }
        for (auto& i : scc) {
            sort(i.begin(), i.end());
        }
        sort(scc.begin(), scc.end());
        for (auto& i : scc) {
            for (auto& j : i) {
                cout << (char)(j + 'A') << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;   
}