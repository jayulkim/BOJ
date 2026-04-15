#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
	ull mod;
	ull norm(ll x) {
		ll m = (ll)mod;
		x %= m;
		if (x < 0) x += m;
		return (ull)x;
	}
	ull addmod_u(ull a, ull b) {
		if (a >= mod - b) {
			return a - (mod - b);
		}
		return a + b;
	}
public:
	Fastmod(ull mod) : mod(mod) {}
	ull addmod(ull a, ull b) {
		return addmod_u(a, b);
	}
	ull addmod(ll a, ll b) {
		return addmod_u(norm(a), norm(b));
	}
	ull fastmulmod(ull a, ull b) {
		long long result = a * b - mod * (ull)(1.L / mod * a * b);
		if (result < 0) {
			result += mod;
		}
		if ((ull)result >= mod) {
			result -= mod;
		}
		return (ull)result;
	}
	ull fastmulmod(ll a, ll b) {
		return fastmulmod(norm(a), norm(b));
	}
	ull mulmod(ull a, ull b) {
		ull result = 0;
		while (b) {
			if (b & 1) {
				result = addmod_u(result, a);
			}
			a = addmod_u(a, a);
			b >>= 1;
		}
		return result;
	}
	ull mulmod(ll a, ll b) {
		return mulmod(norm(a), norm(b));
	}
	ull fastpowmod(ll a, ull b) {
		ull x = norm(a);
		ull result = 1;
		while (b) {
			if (b & 1) {
				result = fastmulmod(result, x);
			}
			x = fastmulmod(x, x);
			b >>= 1;
		}
		return result;
	}
	ull powmod(ll a, ull b) {
		ull x = norm(a);
		ull result = 1;
		while (b) {
			if (b & 1) {
				result = mulmod(result, x);
			}
			x = mulmod(x, x);
			b >>= 1;
		}
		return result;
	}
	ull divmod(ll up, ll down) {
		return fastmulmod(norm(up), fastpowmod(norm(down), mod - 2));
	}
};
class Combination {
private:
	using ull = unsigned long long;
	ull mod;
	Fastmod fm;
public:
	Combination(ull mod) : mod(mod), fm(mod) {}
	ull nCr(ull n, ull r) {
		ull u = 1, d = 1;
		if (r > n) {
			return 0;
		}
		if (r == 0 || n == r) {
			return 1;
		}
		r = min(r, n - r);
		for (int i = 0; i < r; i++) {
			u = fm.fastmulmod(u, n);
			n--;
		}
		for (ull i = 1; i <= r; i++) {
			d = fm.fastmulmod(d, i);
		}
		return fm.fastmulmod(u, fm.fastpowmod(d, mod - 2));
	}
	ull nHr(ull n, ull r) {
		if (n == 0 && r > 0) {
			return 0;
		}
		return nCr(n + r - 1, r);
	}
	ull fastnCr(ull n, ull r, const vector<ull>& factorial, const vector<ull>& invfactorial) {
		if (r > n) {
			return 0;
		}
		if (r == 0 || n == r) {
			return 1;
		}
		return fm.fastmulmod(factorial[n], fm.fastmulmod(invfactorial[r], invfactorial[n - r]));
	}
	ull fastnHr(ull n, ull r, const vector<ull>& factorial, const vector<ull>& invfactorial) {
		if (n == 0 && r > 0) {
			return 0;
		}
		return fastnCr(n + r - 1, r, factorial, invfactorial);
	}
	ull lucasnCr(ull n, ull r) {
		if (r > n) {
			return 0;
		}
		ull result = 1;
		while (n > 0 || r > 0) {
			ull ni = n % mod;
			ull ri = r % mod;
			if (ri > ni) {
				return 0;
			}
			result = fm.fastmulmod(result, nCr(ni, ri));
			n /= mod;
			r /= mod;
		}
		return result;
	}
	ull lucasnHr(ull n, ull r) {
		if (n == 0 && r > 0) {
			return 0;
		}
		return lucasnCr(n + r - 1, r);
	}
};
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll mod = 1000000007;
	vector<ull>factorial(4000001);
	factorial[0] = 1;
	Fastmod fm(mod);
	for (ull i = 1; i <= 4000000; i++) {
		factorial[i] = fm.fastmulmod(factorial[i - 1], i);
	}
	vector<ull>invfactorial(4000001);
	invfactorial[4000000] = fm.fastpowmod(factorial[4000000], mod - 2);
	for (ull i = 4000000; i >= 1; i--) {
		invfactorial[i - 1] = fm.fastmulmod(invfactorial[i], i);
	}
	Combination cb(mod);
	ll num = 0;
	cin >> num;
	while (num--) {
		cin >> n >> m;
		cout << cb.fastnCr(n, m, factorial, invfactorial) << '\n';
	}
	return 0;
}