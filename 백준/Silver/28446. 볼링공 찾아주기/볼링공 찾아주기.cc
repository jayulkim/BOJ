// 기존 방법 : a, b구분안하고 한 집합으로 묶음
// --> a의 1과 b의 2와 a의 3이 한 집합일 때 1은 1끼리만 2는 2끼리만 3은 3끼리만 바꿔야된다? x
// a랑 b구분해서 묶고 a의 것과 b의 것끼리만 바꿔야된다 o
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, char> plc;
typedef pair<string, ll> psl;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll, ll, ll, ll, ll, ll>llllllll;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	map<ll, ll>Map;
	for (int i = 0; i < n; i++) {
		ll a = 0, b = 0, c = 0;
		cin >> a;
		if (a == 1) {
			cin >> a >> b;
			Map[b] = a;
		}
		else {
			cin >> b;
			cout << Map[b] << '\n';
		}
	}
	return 0;
}