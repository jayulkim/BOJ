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
    cin >> n >> m;
    queue<pll>q;
    vector<bool>visited(n + 1, false);
    q.push({ 0, 0 });
    while (!q.empty()) {
        pll temp = q.front();
        q.pop();
        visited[temp.first] = true;
        if (temp.first + 1 <= n && temp.second < m && !visited[temp.first + 1]) {
            q.push({ temp.first + 1, temp.second + 1 });
            visited[temp.first + 1] = true;
        }
        if (temp.first + temp.first / 2 <= n && temp.second < m && !visited[temp.first + temp.first / 2]) {
            q.push({ temp.first + temp.first / 2, temp.second + 1 });
            visited[temp.first + temp.first / 2] = true;
        }
    }
    if (visited[n]) {
        cout << "minigimbob";
    }
    else {
        cout << "water";
    }
    return 0;
 }