#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool visited[1000001];
ll soinsoo[1000001];
ll result = 1;
void eulerphi(ll n) {
    for (int i = 2; i <= n / i; i++) {
        if (soinsoo[i]) {
            for (int j = 0; j < soinsoo[i] - 1; j++) {
                result *= i;
            }
            result *= (i - 1);
        }
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 2; i * i <= 1000000; i++) {
        if (!visited[i]) {
            for (int j = i * i; j <= 1000000; j += i) {
                visited[j] = true;
            }
        }
    }
    ll n = 0;
    cin >> n;
    ll temp = n;
    for (int i = 2; i <= n / i && temp > 1; i++) {
        while (!visited[i] && temp % i == 0) {
            soinsoo[i]++;
            temp /= i;
        }
    }
    if (temp > 1) {
        result *= (temp - 1);
    }
    eulerphi(n);
    cout << result;
    return 0;
}