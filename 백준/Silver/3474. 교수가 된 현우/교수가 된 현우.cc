#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll>tp;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll num = 0;
    cin >> num;
    while (num--) {
        cin >> n;
        ll Min = LLONG_MAX;
        ll sum = 0;
        ll temp = 2;
        while (temp <= n) {
            sum += n / temp;
            temp *= 2;
        }
        Min = min(Min, sum);
        sum = 0;
        temp = 5;
        while (temp <= n) {
            sum += n / temp;
            temp *= 5;
        }
        cout << min(Min, sum) << '\n';
    }
    return 0;
}