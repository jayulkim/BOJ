#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string ary[10][10] = {{"11", "A B C D E F G H J L M"},
                    {"9", "A C E F G H I L M"},
                    {"9", "A C E F G H I L M"},
                    {"9", "A B C E F G H L M"},
                    {"8", "A C E F G H L M"},
                    {"8", "A C E F G H L M"},
                    {"8", "A C E F G H L M"},
                    {"8", "A C E F G H L M"},
                    {"8", "A C E F G H L M"},
                    {"8", "A B C F G H L M"} };
int main(void) {
	ios::sync_with_stdio(false);
    cin.tie(0);
    int n = 0;
    cin >> n;
    cout << ary[n - 1][0] << '\n';
    for (int i = 1; i < 10; i++) {
        cout << ary[n - 1][i] << ' ';
    }
	return 0;
}