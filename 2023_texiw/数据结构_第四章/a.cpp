#include <bits/stdc++.h>
using namespace std;

string s, p;
int ans, res;
const int N = 1e5 + 7;
int stk[N], idx;
int x;
signed main()
{
    freopen("in.txt", "r", stdin);
    cin >> s;
    for (int i = 0; i < s.size(); ++i)
        if (s[i] == ',')
            s[i] = ' ';
    stringstream ss(s);

    while (1) {
        if (ss >> p) {
            try {
                int k = stoi(p);
                stk[++idx] = k;
            } catch (...) {
                res = stk[idx--];
                switch (p[0]) {
                case '+':
                    res = res + stk[idx--];
                    break;
                case '-':
                    res = stk[idx--] - res;
                    break;
                case '*':
                    res = stk[idx--] * res;
                    break;
                case '/':
                    res = stk[idx--] / res;
                    break;
                default:
                    break;
                }
                stk[++idx] = res;
            }
        } else {
            break;
        }
    }
    cout << stk[idx] << endl;
    return 0;
}