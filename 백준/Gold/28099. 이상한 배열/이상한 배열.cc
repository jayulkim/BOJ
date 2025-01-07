#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll num = 0;
    cin >> num;
    while (num--) {
        cin >> n;
        vector<ll>v;
        for (int i = 0; i < n; i++) {
            ll num = 0;
            cin >> num;
            v.push_back(num);
        }
        vector<ll>vv;
        vector<bool>visited(n + 1, false);
        bool a = false;
        for (int i = 0; i < n; i++) {
            if (!visited[v[i]]) {
                while (!vv.empty() && v[i] > vv.back()) {
                    visited[vv.back()] = true;
                    vv.pop_back();
                }
                vv.push_back(v[i]);
            }
            else {
                cout << "No" << '\n';
                a = true;
                break;
            }
        }
        if (!a) {
            cout << "Yes" << '\n';
        }
    }
    return 0;
}