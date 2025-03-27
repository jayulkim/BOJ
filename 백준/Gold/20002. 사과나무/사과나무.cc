//폰 코딩
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
ll Map[301][301];
ll sum[301][301];
int main(void) {
	ios::sync_with_stdio(false);  
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> Map[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + Map[i][j];
        }
    }
    ll Max = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = 1 + i; j <= n; j++) {
            for (int k = 1 + i; k <= n; k++) {
                Max = max(Max, sum[j][k] - sum[j][k - i - 1] - sum[j - i - 1][k] + sum[j - i - 1][k - i - 1]);
            }
        }
    }
    cout << Max;
	return 0;
}