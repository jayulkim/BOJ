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
    vector<vector<char>>v(n + 1, vector<char>(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    ll count = 0;
    map<string, ll>Map;
    for (int i = 0; i < m; i++) {
        string temp = "";
        for (int j = n - 1; j > 0; j--) {
            temp += v[j][i];
        }
        if (Map[temp]) {
            cout << count;
            return 0;
        }
        Map[temp]++;
    }
    count++;
    for (int i = 0; i < n - 2; i++) {
        map<string, ll>updateMap;
        for (auto& j : Map) {
            string temp = j.first;
            temp.pop_back();
            if (updateMap[temp]) {
                cout << count;
                return 0;
            }
            updateMap[temp]++;
        }
        Map = updateMap;
        count++;
    }
    cout << count;
    return 0;
}