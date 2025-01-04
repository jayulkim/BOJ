#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
map<char, ll>Map;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll num = 0;
	cin >> num;
	ll count = 1;
	while (num--) {
		string str = "";
		cin >> str;
		for (auto& i : str) {
			Map[i]++;
		}
		string result = "";
		while (Map['Z']) {
			Map['Z']--;
			Map['E']--;
			Map['R']--;
			Map['O']--;
			result += '0';
		}
		while (Map['G']) {
			Map['E']--;
			Map['I']--;
			Map['G']--;
			Map['H']--;
			Map['T']--;
			result += '8';
		}
		while (Map['W']) {
			Map['T']--;
			Map['W']--;
			Map['O']--;
			result += '2';
		}
		while (Map['X']) {
			Map['S']--;
			Map['I']--;
			Map['X']--;
			result += '6';
		}
		while (Map['U']) {
			Map['F']--;
			Map['O']--;
			Map['U']--;
			Map['R']--;
			result += '4';
		}
		while (Map['F'] && Map['I'] && Map['V'] && Map['E']) {
			Map['F']--;
			Map['I']--;
			Map['V']--;
			Map['E']--;
			result += '5';
		}
		while (Map['S'] && Map['E'] > 1 && Map['V'] && Map['N']) {
			Map['S']--;
			Map['E']--;
			Map['V']--;
			Map['E']--;
			Map['N']--;
			result += '7';
		}
		while (Map['O'] && Map['N'] && Map['E']) {
			Map['O']--;
			Map['N']--;
			Map['E']--;
			result += '1';
		}
		while (Map['T'] && Map['H'] && Map['R'] && Map['E'] > 1) {
			Map['T']--;
			Map['H']--;
			Map['R']--;
			Map['E']--;
			Map['E']--;
			result += '3';
		}
		while (Map['N'] > 1 && Map['I'] && Map['E']) {
			Map['N']--;
			Map['I']--;
			Map['N']--;
			Map['E']--;
			result += '9';
		}
		sort(result.begin(), result.end());
		cout << "Case #" << count++ << ": " << result << '\n';
	}
	return 0;
}