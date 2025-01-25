#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll num = 0;
    cin >> num;
    while (num--) {
        map<string, ll>Map;
        cin >> n;
        for (int i = 0; i < n; i++) {
            string str = "";
            cin >> str;
            Map[str]++;
        }
        bool find = false;
        for (auto& i : Map) {
            if (find) {
                break;
            }
            string temp = "";
            for (auto& j : i.first) {
                if (Map[temp]) {
                    find = true;
                    cout << "NO" << '\n';
                    break;
                }
                temp += j;
            }
        }
        if (!find) {
            cout << "YES" << '\n';
        }
    }
    return 0;
}