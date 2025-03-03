#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    map<ll, ll>Map;
     map<ll, ll>MapMap;
    for (int i = 0; i < n; i++) {
        ll num = 0;
        cin >> num;
        Map[num]++;
    }
    for (int i = 0; i < n; i++) {
        ll num = 0;
        cin >> num;
        MapMap[num]++;
    }
    vector<ll>a;
    vector<ll>b;
    ll count = 0;
    for (auto& i : MapMap) {
        ll temp = 0;
        for (int j = 0; j < i.second; j++) {
             if (Map[i.first]) {
                Map[i.first]--;
                a.push_back(i.first);
                b.push_back(i.first);
                count++;
                 temp++;
            }
            else {
                break;
            }
        } 
        i.second -= temp;
    }
    for (auto& i : Map) {
        while (i.second) {
            a.push_back(i.first);
            i.second--;
        }
    }
    for (auto& i : MapMap) {
        while (i.second) {
            b.push_back(i.first);
            i.second--;
        }
    }
    cout << count << '\n';
    for (auto& i : a) {
        cout << i << ' ';
    }
    cout << '\n';
    for (auto& i : b) {
        cout << i << ' ';
    }
    return 0;
}