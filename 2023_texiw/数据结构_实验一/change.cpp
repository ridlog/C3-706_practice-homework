#include <bits/stdc++.h>
using namespace std;

stack<int> s1;
stack<int> s2;

const int inf = 0x3f3f3f3f;
int yxj;
int f(const char str)
{
    switch (str) {
    case '*':
        yxj = 5;
        break;
    case '/':
        yxj = 5;
        break;
    case '+':
        yxj = 4;
        break;
    case '-':
        yxj = 4;
        break;
    }
    return yxj;
}

string p;
int ans, res;
const int N = 1e5 + 7;
int stk[N], idx;
int x;

void rePolan(string &s)
{
    // cout << s << endl;
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
}

int main()
{
    // char c[1001] = "24 / ( 1 + 2 + 36 / 6 / 2 - 2) * ( 12 / 2 / 2 )     =";
    string c;
    getline(cin, c);
    char d[1001];
    int idx = 0;
    int size = c.size();
    for (int i = 0; i < c.size(); ++i) {
        if (c[i] >= '0' && c[i] <= '9') {
            d[idx++] = c[i];
            continue;
        }
        if (c[i] == ' ' || c[i] == '=')
            continue;
        d[idx++] = ' ';
        d[idx++] = c[i];
        d[idx++] = ' ';
    }
    d[idx] = '\0';
    string s(d);
    stringstream ss(s);
    string p;
    while (ss >> p) {
        try {
            int k = stoi(p);
            s2.push(k);
        } catch (...) {
            if (p[0] == '+' || p[0] == '-' || p[0] == '*' || p[0] == '/') {
                while (true) {
                    if (s1.empty() || s1.top() == '(') {
                        s1.push(p[0]);
                        break;
                    } else if (f(p[0]) > f(s1.top())) {
                        s1.push(p[0]);
                        break;
                    } else {
                        int cc = s1.top();
                        s1.pop();
                        s2.push(cc + inf);
                    }
                }
            } else {
                if (p[0] == '(') {
                    s1.push(p[0]);
                } else if (p[0] == ')') {
                    while ((char)s1.top() != '(') {
                        int ccc = s1.top();
                        s1.pop();
                        s2.push(ccc + inf);
                    }
                    s1.pop();
                }
            }
        }
    }
    while (!s1.empty()) {
        int cccc = s1.top();
        s2.push((int)cccc + inf);
        s1.pop();
    }

    while (!s2.empty()) {
        int c = s2.top();
        if (c >= inf)
            s1.push(c - inf);
        else
            s1.push((int)c + inf);
        s2.pop();
    }
    string t;
    while (!s1.empty()) {
        int u = s1.top();
        if (u < inf) {
            t += (char)u;
            t += ' ';
        } else {
            t += to_string(u - inf);
            t += ' ';
        }
        s1.pop();
    }

    rePolan(t);
    return 0;
}