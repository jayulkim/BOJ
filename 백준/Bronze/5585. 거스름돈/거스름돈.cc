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
    cout << (1000 - n) / 500 + ((1000 - n) % 500) / 100 + (((1000 - n) % 500) % 100) / 50 + ((((1000 - n) % 500) % 100) % 50) / 10 + (((((1000 - n) % 500) % 100) % 50) % 10) / 5 + ((((((1000 - n) % 500) % 100) % 50) % 10) % 5);
    return 0;
}