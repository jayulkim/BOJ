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
    cin >> n >> m;
    string str = "";
    cin >> str;
    ll Min = n;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            for (int k = j; k < n; k++) {
                for (int u = k; u < n; u++) {
                    ll temp = 0;
                    if (i != j && str[i] == str[j] && str[i] != 'X') {
                        temp += j - i + 1;
                    }
                    if (k != u && k != j && str[k] == str[u] && str[k] != 'X') {
                        temp += u - k + 1;
                    }
                    Min = min(Min, n - temp);
                }
            }
        }
    }
    cout << Min;
    return 0;
}