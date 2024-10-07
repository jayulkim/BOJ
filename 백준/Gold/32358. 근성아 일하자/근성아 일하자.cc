#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll, ll>v;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0, temp = 0, result = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll command = 0;
		cin >> command;
		if (command == 1) {
			ll num = 0;
			cin >> num;
			v.insert({ num, num });
		}
		else {
			while (!v.empty()) {
				auto a = v.lower_bound(temp);
				if (a == v.begin()) {
					result += llabs(temp - v[a->first]);
					temp = v[a->first];
					v.erase(a);
				}
				else if (a == v.end()) {
					auto b = a;
					b--;
					result += llabs(temp - v[b->first]);
					temp = v[b->first];
					v.erase(b);
				}
				else {
					auto b = a;
					b--;
					if (llabs(temp - v[b->first]) <= llabs(temp - v[a->first])) {
						result += llabs(temp - v[b->first]);
						temp = v[b->first];
						v.erase(b);
					}
					else {
						result += llabs(temp - v[a->first]);
						temp = v[a->first];
						v.erase(a);
					}
				}
			}
		}
	}
	cout << result;
	return 0;
}