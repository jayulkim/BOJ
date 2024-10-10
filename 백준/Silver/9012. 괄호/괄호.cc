#include <bits/stdc++.h>
using namespace std;
typedef long double ll;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        stack<char> st;
        int flag = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                st.push('(');
            else if (s[i] == ')')
            {
                if (st.size())
                    st.pop();
                else
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (st.size())
            flag = 1;
        if (flag)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}