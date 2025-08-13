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
    vector<vector<ll>>Map(101, vector<ll>(101, 0));
    vector<vector<ll>>forward = { {1, 0}, {-1, 0}, {0, -1}, {0, 1} };
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a = 0, b = 0;
        cin >> a >> b;
        for (int j = a; j < a + 10; j++) {
            for (int k = b; k < b + 10; k++) {
                Map[j][k] = 1;
            }
        }
    }
    ll result = 0;
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            if (Map[i][j]) {
                for (int k = 0; k < 2; k++) {
                    ll dy = i + forward[k][0];
                    ll dx = j + forward[k][1];
                    if (dy >= 0 && dy <= 100 && dx >= 0 && dx <= 100 && !Map[dy][dx]) {
                        result++;
                        break;
                    }
                }
                for (int k = 2; k < 4; k++) {
                    ll dy = i + forward[k][0];
                    ll dx = j + forward[k][1];
                    if (dy >= 0 && dy <= 100 && dx >= 0 && dx <= 100 && !Map[dy][dx]) {
                        result++;
                        break;
                    }
                }
            }
        }
    }
    cout << result;
    return 0; 
}