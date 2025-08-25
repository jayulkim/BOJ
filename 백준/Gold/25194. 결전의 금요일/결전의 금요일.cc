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
    vector<bool>visited(8, false);
    for (int i = 0; i < n; i++) {
        ll num = 0;
        cin >> num;
        vector<bool>visited1(8, false);
        visited1[num % 7] = true;
        for (int j = 0; j < 7; j++) {
            if (visited[j]) {
                visited1[j] = true;
                visited1[(j + num) % 7] = true;
            }
        }
        visited = visited1;
    }
    if (visited[4]) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}