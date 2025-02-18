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
    string str = "";
    cin >> str;
    deque<char>dq;
    ll Min = LLONG_MAX;
    for (int i = 0; i < str.length() + 3; i++) {
        if (i % 3 == 0) {
            dq.push_back('K');
        }
        else if (i % 3 == 1) {
            dq.push_back('S');
        }
        else {
            dq.push_back('A');
        }
    }
    ll idx = 0;
    ll count = 0;
    for (int i = 0; i < str.length() && idx < str.length(); i++) {
        if (str[i] == dq[idx]) {
            count++;
            idx++;
        }
    }
    Min = min(Min, 2 * ((ll)str.length() - count));
    count = 0;
    idx = 0;
    dq.push_back(dq.front());
    dq.pop_front();
    for (int i = 0; i < str.length() && idx < str.length(); i++) {
        if (str[i] == dq[idx]) {
            count++;
            idx++;
        }
    }
    if (str.length() - count >= 2) {
        Min = min(Min, 2 * ((ll)str.length() - count));
    }
    else {
        Min = min(Min, (ll)2);
    }
    count = 0;
    idx = 0;
    dq.push_back(dq.front());
    dq.pop_front();
    for (int i = 0; i < str.length() && idx < str.length(); i++) {
        if (str[i] == dq[idx]) {
            count++;
            idx++;
        }
    }
    if (str.length() - count >= 4) {
        Min = min(Min, 2 * ((ll)str.length() - count));
    }
    else {
        Min = min(Min, (ll)4);
    }
    cout << Min;
    return 0;
}