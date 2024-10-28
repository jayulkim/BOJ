#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0;
ll a = 0, b = 0, c = 0;
bool ary[20000001];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 2; i * i <= 20000000; i++) {
        if (!ary[i]) {
            for (int j = i * i; j <= 20000000; j += i) {
                ary[j] = true;
            }
        }
    }
    vector<ll>prime;
    for (int i = 2; i <= 20000000; i++) {
        if (!ary[i]) {
            prime.push_back(i);
        }
    }
    cin >> n >> m >> k >> a >> b >> c;
    ll x1 = 0, x2 = 0, x3 = 0, x4 = 0, x5 = 0, x6 = 0, x7 = 0;
    for (int i = 0; i < prime.size(); i++) {
        if (n % prime[i] == 0 && n / prime[i] <= 20000000 && !ary[n / prime[i]] && (b % (n / prime[i])) == 0 && (b / (n / prime[i])) <= 20000000 && !ary[(b / (n / prime[i]))]) {
            x1 = prime[i];
            x2 = n / prime[i];
            x3 = b / x2;
            break;
        }
    }
    for (int i = 0; i < prime.size(); i++) {
        if (k % prime[i] == 0 && k / prime[i] <= 20000000 && !ary[k / prime[i]] && c % prime[i] == 0 && c / prime[i] <= 20000000 && !ary[c / prime[i]]) {
            x6 = prime[i];
            x7 = k / prime[i];
            x5 = c / x6;
            break;
        }
    }
    cout << x1 << ' ' << x2 << ' ' << x3 << ' ' << x5 << ' ' << x6 << ' ' << x7;
    return 0;
}