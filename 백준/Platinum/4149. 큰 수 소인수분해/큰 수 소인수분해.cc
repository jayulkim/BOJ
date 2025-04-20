//KACTL millerlabin, pollardrho
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll> lll;
typedef tuple<pll, string, ll> pllsl;
ll n = 0, m = 0, k = 0;
ll mulmod(ll x, ll y, ll num) {
	return (__int128)x * y % num;
}
ll powmod(ll x, ll y, ll num) {
	ll result = 1;
	x %= num;
	while (y) {
		if (y & 1) {
			result = mulmod(result, x, num);
		}
		x = mulmod(x, x, num);
		y >>= 1;
	}
	return result;
}
bool isprime(ll x) {
	// 2 이상의 소수는 전부 6k ± 1 꼴이다.
	// 즉, 6으로 나눈 나머지가 1 또는 5인 애들만 소수일 가능성이 있다.
	if (x < 2 || x % 6 % 4 != 1) {
		// 이땐 그냥 2나 3이면 true 반환
		return (x | 1) == 3;
	}
	// (x - 1)(i) = {(x - 1) / 2, (x - 1) / 4. (x - 1) / 8, ... (x - 1) / 2^s}
	// ary^((x - 1)(i)) (mod x) == ± 1 판별
	// x - 1 = d * 2^s 형태로 분해
	// __builtin_ctzll(x - 1) : (x - 1)(2)의 오른쪽부터 0비트 개수 : 2로 나눌 수 있는 횟수
	ll s = __builtin_ctzll(x - 1);
	// d : (x - 1) / 2^s (홀수)
	ll d = (x - 1) >> s;
	for (ll a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
		ll temp = powmod(a % x, d, x);
		ll i = s;
		// i번만큼 제곱하면서 소수가되는 조건을 만족하는 경우 찾기
		while (temp != 1 && temp != x - 1 && a % x && i--) {
			temp = mulmod(temp, temp, x);
		}
		// 조건을 만족하는 경우를 못 찾았을 때 if(!millerlabin(x, a))
		if (temp != x - 1 && i != s) {
			return false;
		}
	}
	return true;
}
ll pollardrho(ll x) {
	// f(x) = x^2 + 1 (mod n) : random 수열 생성 함수
	auto f = [&](ll a) {
		return (mulmod(a, a, n) + 1) % x;
		};
	ll a = 0, b = 0; // 수열 위의 두 점 (토끼와 거북이)
	ll t = 0; // 반복 횟수
	ll prd = 2; // x, y 차이 누적 곱
	ll i = 1; // x의 초기 시작점
	ll q = 0;
	// 40번이 지난 뒤부터는 __gcd(prd, x) == 1이면 계속 돈다.
	while (t++ % 40 || __gcd(prd, x) == 1) {
		// 토끼와 거북이가 만남
		// 시작점 변경
		if (a == b) {
			a = ++i;
			b = f(a);
		}
		// 차이 곱 누적
		q = mulmod(prd, llabs(a - b), x);
		// 0이 아닐 때만 prd 갱신
		if (q) {
			prd = q;
		}
		// 거북이 한 칸 이동
		a = f(a);
		// 토끼 두 칸 이동
		b = f(f(b));
	}
	return __gcd(prd, x);
}
// x의 소인수를 factors에 저장하겠다.
void factor(ll x, vector<ll>& factors) {
	if (x == 1) {
		return;
	}
	if (isprime(x)) {
		factors.push_back(x);
		return;
	}
	ll temp = pollardrho(x);
	factor(temp, factors);
	factor(x / temp, factors);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	vector<ll>result;
	factor(n, result);
	sort(result.begin(), result.end());
	for (auto& i : result) {
		cout << i << '\n';
	}
	return 0;
}