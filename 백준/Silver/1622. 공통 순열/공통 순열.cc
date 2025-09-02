#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
typedef pair<ll, string> pls;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a = "", b = "";
    while (getline(cin, a) && getline(cin, b)) {
        string temp = "";
        map<char, ll>aa;
        map<char, ll>bb;
        for (auto& i : a) {
            aa[i]++;
        }
        for (auto& i : b) {
            bb[i]++;
        }
        for (auto& i : a) {
            if (bb[i]) {
                for (int j = 0; j < min(aa[i], bb[i]); j++) {
                    temp += i;
                }
                bb[i] = 0;
            }
        }
        sort(temp.begin(), temp.end());
        cout << temp << '\n';
    }
    return 0;
}