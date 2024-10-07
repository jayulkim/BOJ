#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>v;
ll n = 0;
bool visited[9];
void dfs() {
    if (v.size() == n) {
        for (auto& i : v) {
            cout << i << ' ';
        }
        cout << '\n';
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            v.push_back(i);
            visited[i] = true;
            dfs();
            visited[i] = false;
            v.pop_back();
        }
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    dfs();
    return 0;
}