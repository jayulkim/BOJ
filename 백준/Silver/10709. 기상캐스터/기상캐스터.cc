#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll>tp;
ll n = 0, m = 0, k = 0;
char Map[101][101];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> Map[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        ll temp = -1;
        bool find = false;
        for (int j = 0; j < m; j++) {
            if (Map[i][j] == 'c') {
                find = true;
                temp = 0;
                cout << temp << ' ';
            }
            else {
                if (!find) {
                    cout << -1 << ' ';
                }
                else {
                    temp++;
                    cout << temp << ' ';
                } 
            }
        }
        cout << '\n';
    }
    return 0;
}