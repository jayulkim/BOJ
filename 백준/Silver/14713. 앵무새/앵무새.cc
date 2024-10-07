#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n = 0;
    cin >> n;
    queue<string> v[101];
    queue<string> q;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string str = "";
        getline(cin, str);
        str += ' ';
        string result = "";
        for (int j = 0; j < str.length(); j++)
        {
            if (str[j] == ' ')
            {
                if (result != " ")
                v[i].push(result);
                result = "";
            }
            else
            {
                result += str[j];
            }
        }
    }
    string target = "";
    getline(cin, target);
    target += ' ';
    string result = "";
    for (int i = 0; i < target.length(); i++)
    {
        if (target[i] == ' ')
        {
            q.push(result);
            result = ""; 
        }
        else
        {
            result += target[i];
        }
    }
    while (!q.empty())
    {
        int stop = 0;
        for (int i = 0; i < n; i++)
        {
            if (!v[i].empty() && v[i].front() == q.front())
            {
                q.pop();
                v[i].pop();
                stop++;
                break;
            }
        }
        if (stop == 0)
        {
            cout << "Impossible";
            return 0;
        }
    }
    int stop1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (!v[i].empty())
        {
            cout << "Impossible";
            stop1++;
            return 0;  
        }
    }
    if (stop1 == 0)
    {
        cout << "Possible";
    }
}