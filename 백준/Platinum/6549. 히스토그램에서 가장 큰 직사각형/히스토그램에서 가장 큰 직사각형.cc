#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll>tp;
typedef tuple<pll, string, ll>pllsl;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (1) {
        cin >> n;
        if (!n) {
            break;
        }
        vector<ll>v;
        for (int i = 0; i < n; i++) {
            ll num = 0;
            cin >> num;
            v.push_back(num);
        }
        v.push_back(-1);
        ll Max = 0;
        vector<ll>stack;
        for (int i = 0; i <= n; i++) {
            while (!stack.empty() && v[stack.back()] >= v[i]) {
                ll temp = stack.back();
                stack.pop_back();
                if (!stack.empty()) {
                    Max = max(Max, v[temp] * (i - 1 - stack.back()));
                }
                else {
                    Max = max(Max, v[temp] * i);
                }
            }
            stack.push_back(i);
        }
        cout << Max << '\n';
    }
    return 0;
}