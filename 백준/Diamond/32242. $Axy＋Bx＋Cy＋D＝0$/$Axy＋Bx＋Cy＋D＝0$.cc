#include <bits/stdc++.h>
using namespace std;
typedef __int128 ll;
typedef long long l;
ll ary[13] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41 };
l a = 0, b = 0, c = 0, d = 0;
ll addmod(ll x, ll y, ll num) {
	if (x >= (num - y)) {
		return x - (num - y);
	}
	return x + y;
}
ll mulmod(ll x, ll y, ll num) {
	ll result = 0;
	while (y > 0) {
		if (y % 2) {
			result = addmod(result, x, num);
		}
		x = addmod(x, x, num);
		y /= 2;
	}
	return result;
}
ll pow(ll x, ll y) {
	ll result = 1;
	while (y > 0) {
		if (y % 2) {
			result *= x;
		}
		x *= x;
		y /= 2;
	}
	return result;
}
ll powmod(ll x, ll y, ll num) {
	ll result = 1;
	while (y > 0) {
		if (y % 2) {
			result = mulmod(result, x, num);
		}
		x = mulmod(x, x, num);
		y /= 2;
	}
	return result;
}
ll gcd(ll a, ll b) {
	ll temp = a % b;
	while (temp > 0) {
		a = b;
		b = temp;
		temp = a % b;
	}
	return b;
}
ll random(ll x, ll c, ll num) {
	return addmod(mulmod(x, x, num), c, num);
}
bool millerlabin(ll num, ll a) {
	if (num == 1) {
		return false;
	}
	if (num == 2 || num == a) {
		return true;
	}
	ll x = num - 1;
	while (1) {
		ll temp = powmod(a, x, num);
		if (temp == num - 1) {
			return true;
		}
		else {
			if (x % 2 == 0) {
				x /= 2;
			}
			else {
				if (temp == num - 1 || temp % num == 1) {
					return true;
				}
				else {
					return false;
				}
			}
		}
	}
}
bool isprime(ll num) {
	for (ll i = 0; i < 13; i++) {
		if (!millerlabin(num, ary[i])) {
			return false;
		}
	}
	return true;
}
ll pollardrho(ll num) {
	if (num % 2 == 0) {
		return 2;
	}
	if (isprime(num)) {
		return num;
	}
	ll x = (rand() % (num - 2)) + 1;
	ll y = x;
	ll c = (rand() % 3) * 2 - 1;
	ll d = 1;
	while (gcd(d, num) == 1) {
		x = random(x, c, num);
		y = random(y, c, num);
		y = random(y, c, num);
		d = llabs(x - y);
		if (gcd(d, num) == num) {
			return pollardrho(gcd(d, num));
		}
	}
	if (isprime(gcd(d, num))) {
		return gcd(d, num);
	}
	else {
		return pollardrho(gcd(d, num));
	}
}
vector<ll>div(ll num) {
	vector<ll>v;
	v.push_back(1);
	while (num > 1) {
		ll temp = pollardrho(num);
		v.push_back(temp);
		num /= temp;
	}
	return v;
}
vector<ll>soinsoo;
vector<ll>yaksoo = { 1 };
map<ll, ll>Map;
bool Find = false;
void yaksoolist(ll num) {
	soinsoo = div(num);
	sort(soinsoo.begin(), soinsoo.end());
	vector<ll>v = soinsoo;
	v.erase(unique(v.begin(), v.end()), v.end());
	for (auto& i : soinsoo) {
		Map[i]++;
	}
	ll yaksoogaesoo = 1;
	for (ll i = 1; i < v.size(); i++) {
		ll temp = yaksoo.size();
		yaksoogaesoo *= (Map[v[i]] + 1);
		for (ll j = 1; j <= Map[v[i]]; j++) {
			for (int k = 0; k < temp; k++) {
				yaksoo.push_back(yaksoo[k] * pow(v[i], j));
			}
		}
	}
	for (ll i = 0; i < yaksoo.size(); i++) {
		if (yaksoo[i] * yaksoo[i] == num) {
			yaksoo.push_back(yaksoo[i]);
			break;
		}
	}
}
vector<pair<ll, ll>>result;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> b >> c >> d;
	if (a != 0 && b != 0 && c != 0 && d != 0) {
		if (b * c - a * d < 0) {
			yaksoolist(llabs(b * c - a * d));
			sort(yaksoo.begin(), yaksoo.end());
			for (ll i = 0; i < yaksoo.size(); i++) {
				if ((-yaksoo[i] - c) % a == 0 && (yaksoo[yaksoo.size() - 1 - i] - b) % a == 0) {
					result.push_back({ (-yaksoo[i] - c) / a, (yaksoo[yaksoo.size() - 1 - i] - b) / a });
					if (b == c) {
						result.push_back({ (yaksoo[yaksoo.size() - 1 - i] - b) / a, (-yaksoo[i] - c) / a });
					}
				}
				if ((yaksoo[i] - c) % a == 0 && (-yaksoo[yaksoo.size() - 1 - i] - b) % a == 0) {
					result.push_back({ (yaksoo[i] - c) / a, (-yaksoo[yaksoo.size() - 1 - i] - b) / a });
					if (b == c) {
						result.push_back({ (-yaksoo[yaksoo.size() - 1 - i] - b) / a, (yaksoo[i] - c) / a });
					}
				}
			}
			sort(result.begin(), result.end());
			result.erase(unique(result.begin(), result.end()), result.end());
			cout << result.size() << '\n';
			for (auto& i : result) {
				cout << (l)i.first << ' ' << (l)i.second << '\n';
			}
		}
		else if (b * c - a * d > 0) {
			yaksoolist(llabs(b * c - a * d));
			sort(yaksoo.begin(), yaksoo.end());
			for (ll i = 0; i < yaksoo.size(); i++) {
				if ((yaksoo[i] - c) % a == 0 && (yaksoo[yaksoo.size() - 1 - i] - b) % a == 0) {
					result.push_back({ (yaksoo[i] - c) / a, (yaksoo[yaksoo.size() - 1 - i] - b) / a });
					if (b == c) {
						result.push_back({ (yaksoo[yaksoo.size() - 1 - i] - b) / a, (yaksoo[i] - c) / a });
					}
				}
				if ((-yaksoo[i] - c) % a == 0 && (-yaksoo[yaksoo.size() - 1 - i] - b) % a == 0) {
					result.push_back({ (-yaksoo[i] - c) / a, (-yaksoo[yaksoo.size() - 1 - i] - b) / a });
					if (b == c) {
						result.push_back({ (-yaksoo[yaksoo.size() - 1 - i] - b) / a, (-yaksoo[i] - c) / a });
					}
				}
			}
			sort(result.begin(), result.end());
			result.erase(unique(result.begin(), result.end()), result.end());
			cout << result.size() << '\n';
			for (auto& i : result) {
				cout << (l)i.first << ' ' << (l)i.second << '\n';
			}
		}
		else {
			if (c % a == 0 || b % a == 0) {
				cout << "INFINITY";
			}
			else {
				cout << 0;
			}
		}
	}
	else if (a == 0 && b != 0 && c != 0 && d != 0) {
		if (llabs(d) % gcd(llabs(c), llabs(b)) == 0) {
			cout << "INFINITY";
		}
		else {
			cout << 0;
		}
	}
	else if (a != 0 && b == 0 && c != 0 && d != 0) {
		if (b * c - a * d < 0) {
			yaksoolist(llabs(a * d));
			sort(yaksoo.begin(), yaksoo.end());
			for (ll i = 0; i < yaksoo.size(); i++) {
				if ((-yaksoo[i]) % a == 0 && (yaksoo[yaksoo.size() - 1 - i] - c) % a == 0) {
					result.push_back({ (yaksoo[yaksoo.size() - 1 - i] - c) / a, (-yaksoo[i]) / a });
				}
				if ((yaksoo[i]) % a == 0 && (-yaksoo[yaksoo.size() - 1 - i] - c) % a == 0) {
					result.push_back({ (-yaksoo[yaksoo.size() - 1 - i] - c) / a, (yaksoo[i] / a) });
				}
			}
			sort(result.begin(), result.end());
			result.erase(unique(result.begin(), result.end()), result.end());
			cout << result.size() << '\n';
			for (auto& i : result) {
				cout << (l)i.first << ' ' << (l)i.second << '\n';
			}
		}
		else {
			yaksoolist(llabs(a * d));
			sort(yaksoo.begin(), yaksoo.end());
			for (ll i = 0; i < yaksoo.size(); i++) {
				if ((yaksoo[i]) % a == 0 && (yaksoo[yaksoo.size() - 1 - i] - c) % a == 0) {
					result.push_back({ (yaksoo[yaksoo.size() - 1 - i] - c) / a, (yaksoo[i]) / a });
				}
				if ((-yaksoo[yaksoo.size() - 1 - i] - c) % a == 0 && (-yaksoo[i]) % a == 0) {
					result.push_back({ (-yaksoo[yaksoo.size() - 1 - i] - c) / a, (-yaksoo[i]) / a });
				}
			}
			sort(result.begin(), result.end());
			result.erase(unique(result.begin(), result.end()), result.end());
			cout << result.size() << '\n';
			for (auto& i : result) {
				cout << (l)i.first << ' ' << (l)i.second << '\n';
			}
		}
	}
	else if (a != 0 && b != 0 && c == 0 && d != 0) {
		if (b * c - a * d < 0) {
			yaksoolist(llabs(a * d));
			sort(yaksoo.begin(), yaksoo.end());
			for (ll i = 0; i < yaksoo.size(); i++) {
				if ((-yaksoo[i]) % a == 0 && (yaksoo[yaksoo.size() - 1 - i] - b) % a == 0) {
					result.push_back({ (-yaksoo[i]) / a, (yaksoo[yaksoo.size() - 1 - i] - b) / a });
				}
				if ((yaksoo[i]) % a == 0 && (-yaksoo[yaksoo.size() - 1 - i] - b) % a == 0) {
					result.push_back({ (yaksoo[i]) / a, (-yaksoo[yaksoo.size() - 1 - i] - b) / a });
				}
			}
			sort(result.begin(), result.end());
			result.erase(unique(result.begin(), result.end()), result.end());
			cout << result.size() << '\n';
			for (auto& i : result) {
				cout << (l)i.first << ' ' << (l)i.second << '\n';
			}
		}
		else {
			yaksoolist(llabs(a * d));
			sort(yaksoo.begin(), yaksoo.end());
			for (ll i = 0; i < yaksoo.size(); i++) {
				if ((yaksoo[i]) % a == 0 && (yaksoo[yaksoo.size() - 1 - i] - b) % a == 0) {
					result.push_back({ (yaksoo[i]) / a, (yaksoo[yaksoo.size() - 1 - i] - b) / a });
				}
				if ((-yaksoo[i]) % a == 0 && (-yaksoo[yaksoo.size() - 1 - i] - b) % a == 0) {
					result.push_back({ (-yaksoo[i]) / a, (-yaksoo[yaksoo.size() - 1 - i] - b) / a });
				}
			}
			sort(result.begin(), result.end());
			result.erase(unique(result.begin(), result.end()), result.end());
			cout << result.size() << '\n';
			for (auto& i : result) {
				cout << (l)i.first << ' ' << (l)i.second << '\n';
			}
		}
	}
	else if (a != 0 && b != 0 && c != 0 && d == 0) {
		if (b * c < 0) {
			yaksoolist(llabs(b * c));
			sort(yaksoo.begin(), yaksoo.end());
			for (ll i = 0; i < yaksoo.size(); i++) {
				if ((-yaksoo[i] - b) % a == 0 && (yaksoo[yaksoo.size() - 1 - i] - c) % a == 0) {
					result.push_back({ (yaksoo[yaksoo.size() - 1 - i] - c) / a, (-yaksoo[i] - b) / a });
					if (b == c) {
						result.push_back({ (-yaksoo[i] - b) / a , (yaksoo[yaksoo.size() - 1 - i] - c) / a });
					}
				}
				if ((yaksoo[i] - b) % a == 0 && (-yaksoo[yaksoo.size() - 1 - i] - c) % a == 0) {
					result.push_back({ (-yaksoo[yaksoo.size() - 1 - i] - c) / a, (yaksoo[i] - b) / a });
					if (b == c) {
						result.push_back({ (yaksoo[i] - b) / a, (-yaksoo[yaksoo.size() - 1 - i] - c) / a });
					}
				}
			}
			sort(result.begin(), result.end());
			result.erase(unique(result.begin(), result.end()), result.end());
			cout << result.size() << '\n';
			for (auto& i : result) {
				cout << (l)i.first << ' ' << (l)i.second << '\n';
			}
		}
		else {
			yaksoolist(llabs(b * c));
			sort(yaksoo.begin(), yaksoo.end());
			for (ll i = 0; i < yaksoo.size(); i++) {
				if ((yaksoo[i] - b) % a == 0 && (yaksoo[yaksoo.size() - 1 - i] - c) % a == 0) {
					result.push_back({ (yaksoo[yaksoo.size() - 1 - i] - c) / a, (yaksoo[i] - b) / a });
					if (b == c) {
						result.push_back({ (yaksoo[i] - b) / a, (yaksoo[yaksoo.size() - 1 - i] - c) / a });
					}
				}
				if ((-yaksoo[i] - b) % a == 0 && (-yaksoo[yaksoo.size() - 1 - i] - c) % a == 0) {
					result.push_back({ (-yaksoo[yaksoo.size() - 1 - i] - c) / a, (-yaksoo[i] - b) / a });
					if (b == c) {
						result.push_back({ (-yaksoo[i] - b) / a, (-yaksoo[yaksoo.size() - 1 - i] - c) / a });
					}
				}

			}
			sort(result.begin(), result.end());
			result.erase(unique(result.begin(), result.end()), result.end());
			cout << result.size() << '\n';
			for (auto& i : result) {
				cout << (l)i.first << ' ' << (l)i.second << '\n';
			}
		}
	}
	else if (a == 0 && b == 0 && c != 0 && d != 0) {
		if (d % c == 0) {
			cout << "INFINITY";
		}
		else {
			cout << 0;
		}
	}
	else if (a == 0 && b != 0 && c == 0 && d != 0) {
		if (d % b == 0) {
			cout << "INFINITY";
		}
		else {
			cout << 0;
		}
	}
	else if (a == 0 && b != 0 && c != 0 && d == 0) {
		cout << "INFINITY";
	}
	else if (a != 0 && b == 0 && c == 0 && d != 0) {
		if (d % a == 0) {
			if (b * c - a * d < 0) {
				yaksoolist(llabs(d / a));
				sort(yaksoo.begin(), yaksoo.end());
				for (ll i = 0; i < yaksoo.size(); i++) {
					result.push_back({ yaksoo[i], -yaksoo[yaksoo.size() - 1 - i] });
					result.push_back({ -yaksoo[i], yaksoo[yaksoo.size() - 1 - i] });
					result.push_back({ -yaksoo[yaksoo.size() - 1 - i], yaksoo[i] });
					result.push_back({ yaksoo[yaksoo.size() - 1 - i], -yaksoo[i] });
				}
				sort(result.begin(), result.end());
				result.erase(unique(result.begin(), result.end()), result.end());
				cout << result.size() << '\n';
				for (auto& i : result) {
					cout << (l)i.first << ' ' << (l)i.second << '\n';
				}
			}
			else {
				yaksoolist(llabs(d / a));
				sort(yaksoo.begin(), yaksoo.end());
				for (ll i = 0; i < yaksoo.size(); i++) {
					result.push_back({ yaksoo[i], yaksoo[yaksoo.size() - 1 - i] });
					result.push_back({ yaksoo[yaksoo.size() - 1 - i], yaksoo[i] });
					result.push_back({ -yaksoo[yaksoo.size() - 1 - i], -yaksoo[i] });
					result.push_back({ -yaksoo[i], -yaksoo[yaksoo.size() - 1 - i] });
				}
				sort(result.begin(), result.end());
				result.erase(unique(result.begin(), result.end()), result.end());
				cout << result.size() << '\n';
				for (auto& i : result) {
					cout << (l)i.first << ' ' << (l)i.second << '\n';
				}
			}
		}
		else {
			cout << 0;
		}
	}
	else if (a != 0 && b == 0 && c != 0 && d == 0) {
		cout << "INFINITY";
	}
	else if (a != 0 && b != 0 && c == 0 && d == 0) {
		cout << "INFINITY";
	}
	else if (a == 0 && b == 0 && c == 0 && d != 0) {
		cout << 0;
	}
	else if (a == 0 && b == 0 && c != 0 && d == 0) {
		cout << "INFINITY";
	}
	else if (a == 0 && b != 0 && c == 0 && d == 0) {
		cout << "INFINITY";
	}
	else if (a != 0 && b == 0 && c == 0 && d == 0) {
		cout << "INFINITY";
	}
	else if (a == 0 && b == 0 && c == 0 && d == 0) {
		cout << "INFINITY";
	}
	return 0;
}