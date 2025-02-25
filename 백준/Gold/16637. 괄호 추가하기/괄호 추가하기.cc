#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll>tp;
typedef tuple<pll, string, ll>pllsl;
ll n = 0, m = 0, k = 0;
string str = "";
ll Max = LLONG_MIN;
ll getnum(ll sum, char prev, ll num) {
    if (prev == '\0') {
        return num;
    }
    ll result = sum;
    if (prev == '+') {
        result += num;
    }
    if (prev == '-') {
        result -= num;
    }
    if (prev == '*') {
        result *= num;
    }
    return result;
}
void dfs(ll end, ll sum) {
    if (end >= n) {
        Max = max(Max, sum);
        return;
    }
    if (end - 1 >= 0) {
        dfs(end + 2, getnum(sum, str[end - 1], str[end] - '0'));
        if (end + 2 < n) {
            dfs(end + 4, getnum(sum, str[end - 1], getnum(str[end] - '0', str[end + 1], str[end + 2] - '0')));
        }
    }
    else {
        dfs(end + 2, getnum(sum, '\0', str[end] - '0'));
    }
}
int main(void) {
    ios::sync_with_stdio(false);             
    cin.tie(0);
    cin >> n;
    cin >> str;
    dfs(0, 0);
    cout << Max;
    return 0;
}