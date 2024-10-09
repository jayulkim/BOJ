#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void) {
	ios::sync_with_stdio(false);	
    cin.tie(0);
    ll num = 0;
    cin >> num;
    while (num--) {
        vector<ll>v;
        ll temp = 0;
        cin >> temp;
        for (int j = 0; j < 20; j++) {
            ll n = 0;
            cin >> n;
            v.push_back(n);
        }
        ll result = 0;
        vector<ll>stack;
        for(int j = 0; j < 20; j++) {
            ll count = 0;
            for (int k = 0; k < stack.size(); k++) {
                if (stack[k] > v[j]) {
                    count++;
                }
            }
            result += count;
            stack.push_back(v[j]);
        }
        cout << temp << ' ' << result << '\n';
    }
	return 0;
}