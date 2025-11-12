#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef tuple<ll, ll, ll> lll;
typedef tuple<string, string, string> sss;
typedef tuple<string, string, string, string> ssss;
vector<string> solution(vector<string> expressions) {
    vector<string> answer;
    vector<ll>a;
    vector<ll>b;
    ll start = 1;
    for (int i = 0; i < expressions.size(); i++) {
        for (auto& j : expressions[i]) {
            if (isdigit(j)) {
                start = max(start, (ll)j - '0');
            }
        }
        if (expressions[i].back() == 'X') {
            a.push_back(i);
        }
        else {
            b.push_back(i);
        }
    }
    vector<ll>result;
    for (int k = start + 1; k < 10; k++) {
        bool ff = false;
        for (auto& i : b) {
            string str = expressions[i];
            string temp = "";
            bool find = false;
            vector<ll>v;
            bool f = false;
            for (int j = str.length() - 1; j >= 0; j--) {
                if (str[j] == '-') {
                    f = true;
                }
                if (isdigit(str[j])) {
                    find = true;
                }
                else {
                    find = false;
                }
                if (find) {
                    temp += str[j];
                }
                else {
                    if (temp != "") {
                        ll sum = 0;
                        for (int u = 0; u < temp.length(); u++) {
                            sum += pow(k, u) * (temp[u] - '0');
                        }
                        temp = "";
                        v.push_back(sum);
                    }
                }
            }
            ll sum = 0;
            for (int u = 0; u < temp.length(); u++) {
                sum += pow(k, u) * (temp[u] - '0');
            }
            v.push_back(sum);
            if (f) {
                if (v[0] != v[2] - v[1]) {
                    ff = true;
                    break;
                }
            }
            else {
                if (v[0] != v[2] + v[1]) {
                    ff = true;
                    break;
                }
            }
        }
        if (!ff) {
            result.push_back(k);
        }
    }
    for (auto& k : a) {
        string str = expressions[k];
        string r = "";
        bool ff = false;
        for (auto& i : result) {
            string temp = "";
            bool find = false;
            vector<ll>v;
            bool f = false;
            for (int j = str.length() - 1; j >= 0; j--) {
                if (str[j] == '-') {
                    f = true;
                }
                if (isdigit(str[j])) {
                    find = true;
                }
                else {
                    find = false;
                }
                if (find) {
                    temp += str[j];
                }
                else {
                   if (temp != "") {
                        ll sum = 0;
                        for (int u = 0; u < temp.length(); u++) {
                            sum += pow(i, u) * (temp[u] - '0');
                        }
                        temp = "";
                        v.push_back(sum);
                    }
                }
            }
            ll sum = 0;
            for (int u = 0; u < temp.length(); u++) {
                sum += pow(i, u) * (temp[u] - '0');
            }
            v.push_back(sum);
            ll rr = 0;
            if (f) {
                rr = v[1] - v[0];
            }
            else {
                rr = v[0] + v[1];
            }
            string rrr = "";
            while (rr > 0) {
                rrr += to_string(rr % i);
                rr /= i;
            }
            reverse(rrr.begin(), rrr.end());
            if (r == "") {
                r = rrr;
            }
            else if (rrr != r) {
                ff = true;
                break;
            }
        }
        if (!ff) {
            if (r == "") {
                r = "0";
            }
            str.pop_back();
            str += r;
        }
        else {
            str.pop_back();
            str.push_back('?');
        }
        answer.push_back(str);
    }
    return answer;
}