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
	Fastmod(ull mod) {
		this->mod = mod;
	}
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
};
class Primecheck {
private:
	using ull = unsigned long long;
public:
	bool bigisprime(ull x) {
		static const ull sample[] = { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 };
		if (x < 2 || x % 6 % 4 != 1) {
			return (x | 1) == 3;
		}
		Fastmod fm(x);
		ull s = __builtin_ctzll(x - 1);
		ull d = (x - 1) >> s;
		for (ull a : sample) {
			ull temp = fm.fastpowmod(a % x, d);
			ull i = s;
			while (temp != 1 && temp != x - 1 && a % x && i--) {
				temp = fm.fastmulmod(temp, temp);
			}
			if (temp != x - 1 && i != s) {
				return false;
			}
		}
		return true;
	}
	bool isprime(ull x) {
		if (x < 2) {
			return false;
		}
		if (x % 2 == 0) {
			return x == 2;
		}
		for (ull i = 3; i <= x / i; i += 2) {
			if (x % i == 0) {
				return false;
			}
		}
		return true;
	}
	vector<bool> eratosthenes(ull n) {
		vector<bool>result(n + 1, false);
		result[1] = true;
		for (int i = 2; i * i <= n; i++) {
			if (!result[i]) {
				for (int j = i * i; j <= n; j += i) {
					result[j] = true;
				}
			}
		}
		return result;
	}
};
class Fastgcd {
private:
	using ull = unsigned long long;
public:
	ull fastgcd(ull a, ull b) {
		ull shift = 0;
		if (a == 0) {
			return b;
		}
		if (b == 0) {
			return a;
		}
		shift = __builtin_ctzll(a | b);
		a >>= __builtin_ctzll(a);
		do {
			b >>= __builtin_ctzll(b);
			if (a > b) {
				swap(a, b);
			}
			b -= a;
		} while (b);
		return a << shift;
	}
};
class Primefactor {
private:
	using ull = unsigned long long;   
	using pll = pair<ull, ull>;
	Fastgcd fg;
	Primecheck pc;
public:
	ull pollardrho(ull x) {
		if (x % 2 == 0) {
			return 2;
		}
		Fastmod fm(x);
		auto f = [&](ull a) {
			return (fm.fastmulmod(a, a) + 1) % x;
			};
		ull a = 0, b = 0;
		ull t = 30;
		ull prd = 2;
		ull i = 1;
		ull q = 0;
		while (t++ % 40 || fg.fastgcd(prd, x) == 1) {
			if (a == b) {
				a = ++i;
				b = f(a);
			}
			q = fm.fastmulmod(prd, (a > b ? a - b : b - a));
			if (q) {
				prd = q;
			}
			a = f(a);
			b = f(f(b));
			if (!prd) {
				return x;
			}
		}
		return fg.fastgcd(prd, x);
	}
	vector<ull> bigfactor(ull x) {
		vector<ull>result;
		vector<ull>v = { x };
		while (!v.empty()) {
			ull temp = v.back();
			v.pop_back();
			if (temp == 1) {
				continue;
			}
			if (pc.bigisprime(temp)) {
				result.push_back(temp);
				continue;
			}
			ull d = pollardrho(temp);
			v.push_back(d);
			v.push_back(temp / d);
		}
		return result;
	}
	void bigfactor(ull x, vector<ull>& result) {
		vector<ull>v = { x };
		while (!v.empty()) {
			ull temp = v.back();
			v.pop_back();
			if (temp == 1) {
				continue;
			}
			if (pc.bigisprime(temp)) {
				result.push_back(temp);
				continue;
			}
			ull d = pollardrho(temp);
			v.push_back(d);
			v.push_back(temp / d);
		}
	}
	vector<ull> factor(ull x) {
		vector<ull> result;
		for (ull i = 2; i <= x / i; i++) {
			while (x % i == 0) {
				result.push_back(i);
				x /= i;
			}
		}
		if (x > 1) {
			result.push_back(x);
		}
		return result;
	}
	void factor(ull x, vector<ull>& result) {
		for (ull i = 2; i <= x / i; i++) {
			while (x % i == 0) {
				result.push_back(i);
				x /= i;
			}
		}
		if (x > 1) {
			result.push_back(x);
		}
	}
	vector<ull> getdivisor(const vector<ull>& fac) {
		vector<ull>f = fac;
		sort(f.begin(), f.end());
		vector<pll>pf;
		for (auto& i : f) {
			if (pf.empty() || pf.back().first != i) {
				pf.push_back({ i, 1 });
			}
			else {
				pf.back().second++;
			}
		}
		vector<ull>result = { 1 };
		for (auto& [a, b] : pf) {
			size_t size = result.size();
			ull temp = 1;
			for (int i = 1; i <= b; i++) {
				temp *= a;
				for (size_t j = 0; j < size; j++) {
					result.push_back(result[j] * temp);
				}
			}
		}
		return result;
	}
	void getdivisor(const vector<ull>& fac, vector<ull>& v) {
		vector<ull>f = fac;
		sort(f.begin(), f.end());
		vector<pll>pf;
		for (auto& i : f) {
			if (pf.empty() || pf.back().first != i) {
				pf.push_back({ i, 1 });
			}
			else {
				pf.back().second++;
			}
		}
		vector<ull>result = { 1 };
		for (auto& [a, b] : pf) {
			size_t size = result.size();
			ull temp = 1;
			for (int i = 1; i <= b; i++) {
				temp *= a;
				for (size_t j = 0; j < size; j++) {
					result.push_back(result[j] * temp);
				}
			}
		}
		for (auto& i : result) {
			v.push_back(i);
		}
	}
};
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	vector<ull>v;
	vector<ull>fac;
	Primefactor pf;
	for (int i = 0; i < n; i++) {
		cin >> m;
		v.push_back(m);
		pf.bigfactor(m, fac);
	}
	sort(all(fac));
	fac.erase(unique(all(fac)), fac.end());
	ull result = 0;
	for (auto& i : fac) {
		ull count = 0;
		for (int j = 0; j < n; j++) {
			if (v[j] % i) {
				result ^= count;
				count = 0;
			}
			else {
				count++;
			}
		}
		result ^= count;
	}
	if (result) {
		cout << "First";
	}
	else {
		cout << "Second";
	}
	return 0;
}