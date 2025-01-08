#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0;
ll up[100001];
ll down[100001];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    cin.ignore();
    string str = "";
    getline(cin, str);
    str += ' ';
    vector<ll>a;
    vector<ll>b;
    bool find = false;
    string temp = "";
    ll c = 0;
    for (auto& j : str) {
        if (j == ' ' && temp != "") {
            if (!find == 1) {
                a.push_back(stoll(temp));
                find = true;
            }
            else {
                if (c == 1) {
                    a.push_back(stoll(temp));
                }
                else {
                    b.push_back(stoll(temp));
                }
            }
            temp = "";
        }
        else if (j == '/') {
            c = -1;
        }
        else if (j == '*') {
            c = 1;
        }
        if (isdigit(j)) {
            temp += j;
        }
    }
    for (auto& j : a) {
        if (!j) {
            cout << "mint chocolate";
            return 0;
        }
        ll temp = j;
        for (int k = 2; k <= j / k && temp > 1; k++) {
            while (temp % k == 0) {
                up[k]++;
                temp /= k;
            }
        }
        if (temp > 1) {
            up[temp]++;
        }
    }
    for (auto& j : b) {
        ll temp = j;
        for (int k = 2; k <= j / k && temp > 1; k++) {
            while (temp % k == 0) {
                down[k]++;
                temp /= k;
            }
        }
        if (temp > 1) {
            down[temp]++;
        }
    }
    for (int j = 2; j <= 100000; j++) {
        if (up[j] < down[j]) {
            cout << "toothpaste";
            return 0;
        }
    }
    cout << "mint chocolate";
    return 0;
}