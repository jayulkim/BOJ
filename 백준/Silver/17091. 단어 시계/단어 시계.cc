#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string hour[14] = { "\0", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "one"};
string minute[31] = { "\0", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "twenty one", "twenty two", "twenty three", "twenty four", "twenty five", "twenty six", "twenty seven", "twenty eight", "twenty nine" };
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0;
	cin >> n >> m;
	if (m == 0) {
		cout << hour[n] << " o' " << "clock";
	}
	else if (m <= 30) {
		if (m == 1) {
			cout << minute[m] << " minute past " << hour[n];
		}
		else if (m == 15) {
			cout << "quarter past " << hour[n];
		}
		else if (m == 30) {
			cout << "half past " << hour[n];
		}
		else {
			cout << minute[m] << " minutes past " << hour[n];
		}
	}
	else {
		if (60 - m == 1) {
			cout << minute[60 - m] << " minute to " << hour[n + 1];
		}
		else if (m == 45) {
			cout << "quarter to " << hour[n + 1];
		}
		else {
			cout << minute[60 - m] << " minutes to " << hour[n + 1];
		}
	}
	return 0;
}