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
    ll num = 0;
    cin >> num;
    while (num--) {
        cin >> n;
        queue<pll>q;
        vector<bool>visited(n * 2 + 1, false);
        q.push({1, 0});
        bool find = false;
        while (!q.empty()) {
            pll temp = q.front();
            q.pop();
            if (temp.first == n) {
                cout << temp.second << '\n';
                find = true;
                break;
            }
            if (temp.first - 1 >= 1 && !visited[temp.first - 1]) {
                visited[temp.first - 1] = true;
                q.push({ temp.first - 1, temp.second + 1 });
            }
            if (temp.first * 2 <= n * 2 && !visited[temp.first * 2]) {
                visited[temp.first * 2] = true;
                q.push({ temp.first * 2, temp.second + 1 });
            }
        }
        if (!find) {
            cout << "Wrong proof!\n";
        }
    }
    return 0;
 } 