#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<string, string, ll> tp;
typedef pair<ll, ll> pll;
ld n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a = "", b = "";
	cin >> n >> a >> m >> b >> k;
	ld result = 0;
	if (a == "+") {
		result = n + m;
	}
	else if (a == "-") {
		result = n - m;
	}
	else if (a == "*") {
		result = n * m;
	}
	else if (a == "/") {
		result = n / m;
	}
	if (b == "+") {
		result += k;
	}
	else if (b == "-") {
		result -= k;
	}
	else if (b == "*") {
		result *= k;
	}
	else if (b == "/") {
		result /= k;
	}
	result *= 1000;
	result = round(result);
	result /= 1000;
	cout << "=================\n";
	cout << "|SASA CALCULATOR|\n";
	string temp = "|";
	string str = to_string(result);
	string s = "";
	for (int i = str.length() - 4; i >= 0; i--) {
		s += str[i];
	}
	temp += s;
	while (temp.length() < 16) {
		temp += ' ';
	}
	temp += '|';
	reverse(temp.begin(), temp.end());
	cout << temp << '\n';
	cout << "-----------------" << '\n';
	cout << "|               |" << '\n';
	cout << "| AC         /  |" << '\n';
	cout << "| 7  8  9    *  |" << '\n';
	cout << "| 4  5  6    -  |" << '\n';
	cout << "| 1  2  3    +  |" << '\n';
	cout << "|    0  .    =  |" << '\n';
	cout << "=================";
	return 0;
}