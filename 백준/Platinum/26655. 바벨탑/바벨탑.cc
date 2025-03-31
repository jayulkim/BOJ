//폰 코딩
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
vector<ll>vv = { 4, 3, 2, 1 };
ll sum = 0;
vector<ll>s;
ll weight = 0, result = 0;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<ll>v;
    for (int i = 0; i < n; i++) {
        ll num = 0;
        cin >> num;
        v.push_back((num - 20) / 10);
    }
    for (int i = 0; i < n; i++) {
        if (v[i] > sum) {
            s.push_back(v[i] - sum);
            weight += v[i] - sum;
            sum = v[i];
        }
        else {
            while (sum > v[i]) {
                ll temp = s.back();
                s.pop_back();
                if (temp > sum - v[i]) {
                    ll num = sum - v[i];
                    for (int j = 0; j < 4 && num > 0; j++) {
                        if (num / vv[j]) {
                            weight += (num / vv[j]) * vv[j];
                            result += 2 * (num / vv[j]);
                            num -= (num / vv[j]) * vv[j];
                        }
                    }
                    temp -= (sum - v[i]);
                    s.push_back(temp);
                    sum = v[i];
                }
                else {
                    sum -= temp;
                    for (int j = 0; j < 4 && temp > 0; j++) {
                        if (temp / vv[j]) {
                            weight += (temp / vv[j]) * vv[j];
                            result += 2 * (temp / vv[j]);
                            temp -= (temp / vv[j]) * vv[j];
                        }
                    }
                }
            }
        }
    }
    while (!s.empty()) {
        ll temp = s.back();
        s.pop_back();
        for (int j = 0; j < 4 && temp > 0; j++) {
            if (temp / vv[j]) {
                weight += (temp / vv[j]) * vv[j];
                result += 2 * (temp / vv[j]);
                temp -= (temp / vv[j]) * vv[j];
            }
        }
    }
    cout << weight * 10 << ' ' << result * 2;
    return 0;
}