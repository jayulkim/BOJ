#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll>tp;
typedef tuple<pll, string, ll>pllsl;
ll n = 0, m = 0, k = 0;
vector<ll>v;
ll check() {
    vector<ll>stack;
    ll num = 0;
    for (int i = 0; i < n; i++) {    
        ll temp = stack.size();
        if (temp >= 4 && stack[temp - 1] == stack[temp - 2] && stack[temp - 2] == stack[temp - 3] && stack[temp - 3] == stack[temp - 4]) {
            num = stack[temp - 1];
        }
        if (num && v[i] != num) {
            while (!stack.empty() && stack.back() == num) {
                stack.pop_back();
            }
            num = 0;
        }
        stack.push_back(v[i]);
    }
    ll temp = stack.size();
    if (temp >= 4 && stack[temp - 1] == stack[temp - 2] && stack[temp - 2] == stack[temp - 3] && stack[temp - 3] == stack[temp - 4]) {
        num = stack[temp - 1];
    }
    while (!stack.empty() && stack.back() == num) {
        stack.pop_back();
    }
    num = 0;
    return stack.size();
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll num = 0;
        cin >> num;
        v.push_back(num);
    }
    ll Min = n;
    for (int i = 0; i < n - 3; i++) {
        map<ll, ll>Map;
        for (int j = i; j <= i + 3; j++) {
            Map[v[j]]++;
        }
        if (Map.size() == 2) {
            pll a = { 0, 0 };
            pll b = { 0, 0 };
            for (auto& j : Map) {
                if (j.second == 3) {
                    a.first++;
                    a.second = j.first;
                }
                else if (j.second == 1) {
                    b.first++;
                    b.second = j.first;
                }
            }
            if (a.first == 1 && b.first == 1) {
                ll idx = -1;
                for (int j = i; j <= i + 3; j++) {
                    if (v[j] == b.second) {
                        idx = j;
                        break;
                    }
                }
                v[idx] = a.second;
                Min = min(Min, check());
                v[idx] = b.second;
            }
        }
    }
    cout << Min;
    return 0;
}