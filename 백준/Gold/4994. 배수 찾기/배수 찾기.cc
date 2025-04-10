//폰 코딩
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (1) {
        cin >> n;
        if (!n) {
            break;
        }
        queue<psl>q;
        vector<bool>visited(201, false);
        q.push({"1", 1 % n});
        while (!q.empty()) {
            psl temp = q.front();
            q.pop();
            visited[temp.second] = true;
            if (!temp.second) {
                cout << temp.first << '\n';
                break;
            }
            if (!visited[(temp.second * 10) % n]) {
                visited[(temp.second * 10) % n] = true;
                q.push({temp.first + '0', (temp.second * 10) % n});
            }
            if (!visited[(temp.second * 10 + 1) % n]) {
                visited[(temp.second * 10 + 1) % n] = true;
                q.push({temp.first + '1', (temp.second * 10 + 1) % n});
            }
        }
    }
    return 0;
}