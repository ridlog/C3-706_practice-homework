#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int n, q[N], hh = 1, tt, x;

signed main()
{
    freopen("in.txt", "r", stdin);
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            cin >> x;
            q[++tt] = x;
        }
        while (1) {
            int t = tt;
            tt = hh - 1;
            for (int i = hh; i <= t; ++i) {
                if ((i == hh || q[i] >= q[i - 1]) && (i == t || q[i] <= q[i + 1])) {
                    q[++tt] = q[i];
                }
            }
            if (t == tt || tt == hh - 1) {
                int len = tt - hh + 1;
                cout << len << endl;
                for (int i = 0; i < len; ++i) {
                    cout << q[hh++] << ' ';
                }
                cout << endl;
                break;
            }
        }
    }
    return 0;
}