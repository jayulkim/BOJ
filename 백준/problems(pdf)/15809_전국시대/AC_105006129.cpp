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
//class Primecheck {
//private:
//	using ull = unsigned long long;
//public:
//	bool bigisprime(ull x) {
//		static const ull sample[] = { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 };
//		if (x < 2 || x % 6 % 4 != 1) {
//			return (x | 1) == 3;
//		}
//		Fastmod fm(x);
//		ull s = __builtin_ctzll(x - 1);
//		ull d = (x - 1) >> s;
//		for (ull a : sample) {
//			ull temp = fm.fastpowmod(a % x, d);
//			ull i = s;
//			while (temp != 1 && temp != x - 1 && a % x && i--) {
//				temp = fm.fastmulmod(temp, temp);
//			}
//			if (temp != x - 1 && i != s) {
//				return false;
//			}
//		}
//		return true;
//	}
//	bool isprime(ull x) {
//		if (x < 2) {
//			return false;
//		}
//		if (x % 2 == 0) {
//			return x == 2;
//		}
//		for (ull i = 3; i <= x / i; i += 2) {
//			if (x % i == 0) {
//				return false;
//			}
//		}
//		return true;
//	}
//	vector<bool> eratosthenes(ull n) {
//		vector<bool>result(n + 1, false);
//		result[1] = true;
//		for (int i = 2; i * i <= n; i++) {
//			if (!result[i]) {
//				for (int j = i * i; j <= n; j += i) {
//					result[j] = true;
//				}
//			}
//		}
//		return result;
//	}
//};
//class Fastgcd {
//private:
//	using ll = long long;
//	using ull = unsigned long long;
//	using lll = tuple<ll, ll, ll>;
//public:
//	ull fastgcd(ull a, ull b) {
//		ull shift = 0;
//		if (a == 0) {
//			return b;
//		}
//		if (b == 0) {
//			return a;
//		}
//		shift = __builtin_ctzll(a | b);
//		a >>= __builtin_ctzll(a);
//		do {
//			b >>= __builtin_ctzll(b);
//			if (a > b) {
//				swap(a, b);
//			}
//			b -= a;
//		} while (b);
//		return a << shift;
//	}
//	lll eea(ll a, ll mod) {
//		ll r1 = a, r2 = mod;
//		ll s1 = 1, s2 = 0;
//		ll t1 = 0, t2 = 1;
//		while (r2) {
//			ll q = r1 / r2;
//			ll r = r1 - q * r2;
//			r1 = r2;
//			r2 = r;
//			ll s = s1 - q * s2;
//			s1 = s2;
//			s2 = s;
//			ll t = t1 - q * t2;
//			t1 = t2;
//			t2 = t;
//		}
//		return { r1, s1, t1 };
//	}
//};
//class Primefactor {
//private:
//	using ll = long long;
//	using ull = unsigned long long;
//	using pull = pair<ull, ull>;
//	using pll = pair<ll, ll>;
//	Fastgcd fg;
//	Primecheck pc;
//public:
//	ull pollardrho(ull x) {
//		if (x % 2 == 0) {
//			return 2;
//		}
//		Fastmod fm(x);
//		auto f = [&](ull a) {
//			return (fm.fastmulmod(a, a) + 1) % x;
//			};
//		ull a = 0, b = 0;
//		ull t = 30;
//		ull prd = 2;
//		ull i = 1;
//		ull q = 0;
//		while (t++ % 40 || fg.fastgcd(prd, x) == 1) {
//			if (a == b) {
//				a = ++i;
//				b = f(a);
//			}
//			q = fm.fastmulmod(prd, (a > b ? a - b : b - a));
//			if (q) {
//				prd = q;
//			}
//			a = f(a);
//			b = f(f(b));
//			if (!prd) {
//				return x;
//			}
//		}
//		return fg.fastgcd(prd, x);
//	}
//	vector<ull> bigfactor(ull x) {
//		vector<ull>result;
//		vector<ull>v = { x };
//		while (!v.empty()) {
//			ull temp = v.back();
//			v.pop_back();
//			if (temp == 1) {
//				continue;
//			}
//			if (pc.bigisprime(temp)) {
//				result.push_back(temp);
//				continue;
//			}
//			ull d = pollardrho(temp);
//			v.push_back(d);
//			v.push_back(temp / d);
//		}
//		return result;
//	}
//	void bigfactor(ull x, vector<ull>& result) {
//		vector<ull>v = { x };
//		while (!v.empty()) {
//			ull temp = v.back();
//			v.pop_back();
//			if (temp == 1) {
//				continue;
//			}
//			if (pc.bigisprime(temp)) {
//				result.push_back(temp);
//				continue;
//			}
//			ull d = pollardrho(temp);
//			v.push_back(d);
//			v.push_back(temp / d);
//		}
//	}
//	vector<ull> factor(ull x) {
//		vector<ull> result;
//		for (ull i = 2; i <= x / i; i++) {
//			while (x % i == 0) {
//				result.push_back(i);
//				x /= i;
//			}
//		}
//		if (x > 1) {
//			result.push_back(x);
//		}
//		return result;
//	}
//	void factor(ull x, vector<ull>& result) {
//		for (ull i = 2; i <= x / i; i++) {
//			while (x % i == 0) {
//				result.push_back(i);
//				x /= i;
//			}
//		}
//		if (x > 1) {
//			result.push_back(x);
//		}
//	}
//	vector<pll> factorialfactor(ull n, const vector<ll>& prime) {
//		vector<pll>result;
//		for (auto& i : prime) {
//			ull count = 0;
//			for (ull j = i; j <= n;) {
//				count += n / j;
//				if (j > n / i) {
//					break;
//				}
//				j *= i;
//			}
//			if (count > 0) {
//				result.push_back({ i, count });
//			}
//		}
//		return result;
//	}
//	void factorialfactor(ull n, const vector<ll>& prime, vector<ll>& result) {
//		for (auto& i : prime) {
//			ull count = 0;
//			for (ull j = i; j <= n;) {
//				count += n / j;
//				if (j > n / i) {
//					break;
//				}
//				j *= i;
//			}
//			if (count > 0) {
//				result[i] += count;
//			}
//		}
//	}
//	vector<ull> getbigdivisor(ull n) {
//		vector<ull>f = bigfactor(n);
//		sort(f.begin(), f.end());
//		vector<pull>pf;
//		for (auto& i : f) {
//			if (pf.empty() || pf.back().first != i) {
//				pf.push_back({ i, 1 });
//			}
//			else {
//				pf.back().second++;
//			}
//		}
//		vector<ull>result = { 1 };
//		for (auto& [a, b] : pf) {
//			size_t size = result.size();
//			ull temp = 1;
//			for (int i = 1; i <= b; i++) {
//				temp *= a;
//				for (size_t j = 0; j < size; j++) {
//					result.push_back(result[j] * temp);
//				}
//			}
//		}
//		return result;
//	}
//	void getbigdivisor(ull n, vector<ull>& result) {
//		vector<ull>f = bigfactor(n);
//		sort(f.begin(), f.end());
//		vector<pull>pf;
//		for (auto& i : f) {
//			if (pf.empty() || pf.back().first != i) {
//				pf.push_back({ i, 1 });
//			}
//			else {
//				pf.back().second++;
//			}
//		}
//		vector<ull>v = { 1 };
//		for (auto& [a, b] : pf) {
//			size_t size = v.size();
//			ull temp = 1;
//			for (int i = 1; i <= b; i++) {
//				temp *= a;
//				for (size_t j = 0; j < size; j++) {
//					v.push_back(v[j] * temp);
//				}
//			}
//		}
//		for (auto& i : v) {
//			result.push_back(i);
//		}
//	}
//	vector<ull> getdivisor(ull n) {
//		vector<ull> result;
//		for (ull i = 1; i <= n / i; i++) {
//			if (n % i == 0) {
//				result.push_back(i);
//				if (i != n / i) {
//					result.push_back(n / i);
//				}
//			}
//		}
//		return result;
//	}
//	void getdivisor(ull n, vector<ull>& result) {
//		for (ull i = 1; i <= n / i; i++) {
//			if (n % i == 0) {
//				result.push_back(i);
//				if (i != n / i) {
//					result.push_back(n / i);
//				}
//			}
//		}
//	}
//};
//class Eulerphi {
//private:
//	using ull = unsigned long long;
//	Primefactor pf;
//public:
//	ull eulerphi(ull n) {
//		ull result = 1;
//		for (ull i = 2; i <= n / i; i++) {
//			if (n % i == 0) {
//				while (n % i == 0) {
//					result *= i;
//					n /= i;
//				}
//				result /= i;
//				result *= (i - 1);
//			}
//		}
//		if (n > 1) {
//			result *= (n - 1);
//		}
//		return result;
//	}
//	ull bigeulerphi(ull n) {
//		vector<ull> fac = pf.bigfactor(n);
//		sort(fac.begin(), fac.end());
//		fac.erase(unique(fac.begin(), fac.end()), fac.end());
//		ull result = n;
//		for (ull p : fac) {
//			result = result / p * (p - 1);
//		}
//		return result;
//	}
//};
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
class Dijkstra {
private:
	using ll = long long;
	using pll = pair<ll, ll>;
	ll n;
	vector<vector<pll>>graph;
public:
	vector<ll>dist;
	vector<vector<pll>>revgraph;
	Dijkstra(ll n, const vector<vector<pll>>& graph) : n(n), graph(graph) {}
	vector<ll> run(const vector<ll>& start) {
		priority_queue<pll, vector<pll>, greater<pll>>pq;
		dist.assign(n + 1, LLONG_MAX);
		for (auto& i : start) {
			dist[i] = 0;
			pq.push({ 0, i });
		}
		while (!pq.empty()) {
			auto [a, b] = pq.top();
			pq.pop();
			if (dist[b] >= a) {
				for (auto& i : graph[b]) {
					if (dist[i.first] > dist[b] + i.second) {
						dist[i.first] = dist[b] + i.second;
						pq.push({ dist[i.first], i.first });
					}
				}
			}
		}
		return dist;
	}
	pair<vector<ll>, vector<vector<pll>>> revrun(const vector<ll>& start) {
		priority_queue<pll, vector<pll>, greater<pll>>pq;
		dist.assign(n + 1, LLONG_MAX);
		revgraph.assign(n + 1, vector<pll>());
		for (auto& i : start) {
			dist[i] = 0;
			pq.push({ 0, i });
		}
		while (!pq.empty()) {
			auto [a, b] = pq.top();
			pq.pop();
			if (dist[b] >= a) {
				for (auto& i : graph[b]) {
					if (dist[i.first] > dist[b] + i.second) {
						vector<pll>().swap(revgraph[i.first]);
						revgraph[i.first].push_back({ b, i.second });
						dist[i.first] = dist[b] + i.second;
						pq.push({ dist[i.first], i.first });
					}
					else if (dist[i.first] == dist[b] + i.second) {
						revgraph[i.first].push_back({ b, i.second });
					}
				}
			}
		}
		return { dist, revgraph };
	}
};
class Toposort {
private:
	using ll = long long;
	ll n;
	vector<vector<ll>>dag;
public:
	Toposort(ll n, const vector<vector<ll>>& dag) : n(n), dag(dag) {}
	pair<bool, vector<ll>> toposort() {
		vector<ll>degree(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			for (auto& j : dag[i]) {
				degree[j]++;
			}
		}
		vector<ll>result;
		queue<ll>q;
		for (int i = 1; i <= n; i++) {
			if (!degree[i]) {
				q.push(i);
			}
		}
		while (!q.empty()) {
			ll temp = q.front();
			q.pop();
			result.push_back(temp);
			for (auto& i : dag[temp]) {
				if (--degree[i] == 0) {
					q.push(i);
				}
			}
		}
		return { result.size() == n, result };
	}
};
class Unionfind {
private:
	using ll = long long;
	using pll = pair<ll, ll>;
	using lll = tuple<ll, ll, ll>;
	ll n;
	vector<ll>parent;
	vector<ll>rank;
public:
	void init() {
		parent.resize(n + 1);
		iota(parent.begin(), parent.end(), 0);
		rank.assign(n + 1, 1);
	}
	Unionfind(ll n) : n(n) {
		init();
	}
	ll getparent(ll x) {
		if (x == parent[x]) {
			return x;
		}
		return parent[x] = getparent(parent[x]);
	}
	void merge(ll a, ll b) {
		a = getparent(a);
		b = getparent(b);
		if (a == b) {
			return;
		}
		if (rank[a] > rank[b]) {
			rank[a] += rank[b];
			rank[b] = 0;
			parent[b] = a;
		}
		else {
			rank[b] += rank[a];
			rank[a] = 0;
			parent[a] = b;
		}
	}
	void merge(ll a, ll b, ll c, vector<ll>& rank) {
		a = getparent(a);
		b = getparent(b);
		if (a == b) {
			return;
		}
		if (c == 1) {
			if (rank[a] > rank[b]) {
				rank[a] += rank[b];
				rank[b] = 0;
				parent[b] = a;
			}
			else {
				rank[b] += rank[a];
				rank[a] = 0;
				parent[a] = b;
			}
		}
		else {
			if (rank[a] > rank[b]) {
				rank[a] -= rank[b];
				rank[b] = 0;
				parent[b] = a;
			}
			else {
				rank[b] -= rank[a];
				rank[a] = 0;
				parent[a] = b;
			}
		}
	}
	ll minkruskal(priority_queue<lll, vector<lll>, greater<lll>>& pq) {
		init();
		ll result = 0;
		ll count = 0;
		while (!pq.empty() && count < n - 1) {
			auto [a, b, c] = pq.top();
			pq.pop();
			if (getparent(b) != getparent(c)) {
				count++;
				result += a;
				merge(b, c);
			}
		}
		return (count == n - 1 ? result : LLONG_MAX);
	}
	ll maxkruskal(priority_queue<lll>& pq) {
		init();
		ll result = 0;
		ll count = 0;
		while (!pq.empty() && count < n - 1) {
			auto [a, b, c] = pq.top();
			pq.pop();
			if (getparent(b) != getparent(c)) {
				count++;
				result += a;
				merge(b, c);
			}
		}
		return (count == n - 1 ? result : LLONG_MAX);
	}
	bool hascycle(const vector<vector<ll>>& graph) {
		init();
		for (int i = 1; i <= n; i++) {
			for (auto& j : graph[i]) {
				if (i < j) {
					if (getparent(i) == getparent(j)) {
						return true;
					}
					merge(i, j);
				}
			}
		}
		return false;
	}
	bool hascycle(const vector<vector<pll>>& graph) {
		init();
		for (int i = 1; i <= n; i++) {
			for (auto& j : graph[i]) {
				if (i < j.first) {
					if (getparent(i) == getparent(j.first)) {
						return true;
					}
					merge(i, j.first);
				}
			}
		}
		return false;
	}
};
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	vector<ll>v(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	Unionfind uf(n);
	for (int i = 0; i < m; i++) {
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		uf.merge(b, c, a, v);
	}
	vector<ll>result;
	for (int i = 1; i <= n; i++) {
		if (v[i]) {
			result.push_back(v[i]);
		}
	}
	cout << result.size() << '\n';
	sort(all(result));
	for (auto& i : result) {
		cout << i << ' ';
	}
	return 0;
}