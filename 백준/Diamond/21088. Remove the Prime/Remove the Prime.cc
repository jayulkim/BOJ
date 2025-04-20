//KACTL millerlabin, pollardrho
// from https://seastar105.tistory.com/89
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll> lll;
typedef tuple<pll, string, ll> pllsl;
ll n = 0, m = 0, k = 0;
// https://github.com/kth-competitive-programming/kactl/blob/master/content/number-theory/ModMulLL.h
ull mulmod(ull x, ull y, ull num) {
	// x * y - num * [(x * y) / num]와 유사한 계산
	// ull(1.L / num * x * y) : (x * y) * (1.L / num) : 부동소수점 연산, (x * y / num) 근사
	// 1.L : 1.0 (long double 상수)
	ll result = x * y - num * ull(1.L / num * x * y);
	// result를 [0, num) 범위로 보정
	if (result < 0) {
		return result + num;
	}
	if (result >= (ll)num) {
		return result - num;
	}
	return result;
}
ull powmod(ull x, ull y, ull num) {
	ull result = 1;
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
// https://github.com/kth-competitive-programming/kactl/blob/main/content/number-theory/MillerRabin.h
bool isprime(ull x) {
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
	ull s = __builtin_ctzll(x - 1);
	// d : (x - 1) / 2^s (홀수)
	ull d = (x - 1) >> s;
	for (ll a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
		ull temp = powmod(a % x, d, x);
		ull i = s;
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
// https://lemire.me/blog/2013/12/26/fastest-way-to-compute-the-greatest-common-divisor/
ull bgcd(ull a, ull b) {
	// 1. 둘다 짝수일 때는 2로 나눈다.
	// 2. 하나만 짝수일 때는 그 수만 2로 나눈다.
	// 3. 두 수가 홀수일 때는 큰 수에서 작은 수를 뺀다.
	// 4. 0이 되는 수가 있으면 종료
	// c = 1번 연산을 한 횟수
	// gcd(a, b) = 2^c * (둘 중 0이 아닌 수)
	// a, b에 2가 c개 있다.
	// 4번 연산의 바로 전에 무조건 3번 연산을 했고 두 수는 같음이 자명하다.
	// 그 같았던 두 수가 a, b에 포함돼있기 때문에 마지막 남은 둘 중 0이 아닌 수를 곱한다.
	ull shift = 0;
	// gcd(0, b) = b
	if (a == 0) {
		return b;
	}
	// gcd(a, 0) = a
	if (b == 0) {
		return a;
	}
	// __builtin_ctzll(a | b) : a | b의 오른쪽부터 0비트 개수 : a, b가 공통으로 갖는 2의 제곱수 : 1번 연산 횟수 
	shift = __builtin_ctzll(a | b);
	// a의 맨 오른쪽 비트 1로 만들기 : 홀수로 만들기
	a >>= __builtin_ctzll(a);
	do {
		// b도 홀수로 만들기
		b >>= __builtin_ctzll(b);
		// a <= b 유지
		if (a > b) {
			swap(a, b);
		}
		// 3번 연산
		b -= a;
	} while (b);
	// gcd(a, b) = a * 2^shift
	return a << shift;
}
// https://github.com/kth-competitive-programming/kactl/blob/main/content/number-theory/Factor.h
ull pollardrho(ull x) {
	if (x % 2 == 0) {
		return 2;
	}
	// f(x) = x^2 + 1 (mod n) : random 수열 생성 함수
	auto f = [&](ull a) {
		return (mulmod(a, a, x) + 1) % x;
		};
	ull a = 0, b = 0; // 수열 위의 두 점 (토끼와 거북이)
	ull t = 30; // 반복 횟수
	ull prd = 2; // x, y 차이 누적 곱
	ull i = 1; // x의 초기 시작점
	ull q = 0;
	// 40번이 지난 뒤부터는 __gcd(prd, x) == 1이면 계속 돈다.
	while (t++ % 40 || bgcd(prd, x) == 1) {
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
		if (!prd) {
			return x;
		}
	}
	return bgcd(prd, x);
}
// x의 소인수를 factors에 저장하겠다.
void factor(ull x, vector<ull>& factors) {
	if (x == 1) {
		return;
	}
	if (isprime(x)) {
		factors.push_back(x);
		return;
	}
	ull temp = pollardrho(x);
	factor(temp, factors);
	factor(x / temp, factors);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	vector<ull>Map;
	vector<ull>v;
	for (int i = 0; i < n; i++) {
		ull num = 0;
		cin >> num;
		v.push_back(num);
		factor(num, Map);
	}
	sort(Map.begin(), Map.end());
	Map.erase(unique(Map.begin(), Map.end()), Map.end());
	ull result = 0;
	for (auto& i : Map) {
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