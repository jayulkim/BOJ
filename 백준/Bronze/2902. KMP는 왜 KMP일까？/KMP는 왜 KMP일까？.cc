#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str = "";
    cin >> str;
    string temp = "";
    temp += str[0];
    vector<ll>v;
    for (int i = 1; i < str.length(); i++) {
        if (str[i] == '-') {
            v.push_back(i);
        }
    }
    for (auto& i : v) {
        temp += str[i + 1];
    }
    cout << temp;
    return 0;
}