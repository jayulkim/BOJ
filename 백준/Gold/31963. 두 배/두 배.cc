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
    cin >> n;
    vector<ll>v(n + 1, 0);
    ll count = 0;
    ll prev = 0;
    for (int i = 0; i < n; i++) {
        ll num = 0;
        cin >> num;
        if (i) {
            ll temp = num;
            if (prev > num / pow(2, v[i - 1])) {
                count += v[i - 1];
                v[i] += v[i - 1];
                while (prev < num) {
                    count--;
                    num /= 2;
                    v[i]--;
                }
                while (prev > num) {
                    num *= 2;
                    count++;
                    v[i]++;
                }
            }
            prev = temp;
        }
        else {
            prev = num;
        }
    }
    cout << count;
    return 0;
}