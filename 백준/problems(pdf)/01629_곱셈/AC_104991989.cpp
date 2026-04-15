#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;
ll n = 0, m = 0, k = 0;
class Fastmod {
private:
	using ll = long long;
	using ull = unsigned long long;
	ll mod;
	ll norm(ll x) {
		x %= mod;
		if (x < 0) x += mod;
		return x;
	}
public:
	Fastmod(ll mod) {
		this->mod = mod;
	}
	ll addmod(ll a, ll b) {
		a = norm(a);
		b = norm(b);
		if (a >= mod - b) {
			return a - (mod - b);
		}
		return a + b;
	}
	ll fastmulmod(ll a, ll b) {
		a = norm(a);
		b = norm(b);
		ll result = a * b - mod * ll(1.L / mod * a * b);
		if (result < 0) {
			return result + mod;
		}
		if (result >= (ll)mod) {
			return result - mod;
		}
		return result;
	}
	ll mulmod(ll a, ll b) {
		a = norm(a);
		b = norm(b);
		ll result = 0;
		while (b) {
			if (b & 1) {
				result = addmod(result, a);
			}
			a = addmod(a, a);
			b >>= 1;
		}
		return result;
	}
	ll fastpowmod(ll a, ll b) {
		a = norm(a);
		ll result = 1;
		while (b) {
			if (b & 1) {
				result = fastmulmod(result, a);
			}
			a = fastmulmod(a, a);
			b >>= 1;
		}
		return result;
	}
	ll powmod(ll a, ll b) {
		a = norm(a);
		ll result = 1;
		while (b) {
			if (b & 1) {
				result = mulmod(result, a);
			}
			a = mulmod(a, a);
			b >>= 1;
		}
		return result;
	}
};
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	Fastmod f(k);
	cout << f.fastpowmod(n, m);
	return 0;
}