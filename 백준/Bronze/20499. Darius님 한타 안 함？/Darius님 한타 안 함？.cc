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
    string str = "";
    cin >> str;
    vector<ll>v;
    string temp = "";
    for (auto& i : str) {
        if (i == '/') {
            v.push_back(stoll(temp));
            temp = "";
        }
        else {
            temp += i;
        }
    }
    v.push_back(stoll(temp));
    if (v[0] + v[2] < v[1] || !v[1]) {
        cout << "hasu";
    }
    else {
        cout << "gosu";
    }
    return 0;
}