#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
int m, n, x, y;
int res;
int a[N][N], s[N][N];
signed main()
{
    freopen("in.txt", "r", stdin);
    cin >> m >> n >> x >> y;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }
    for (int i = x; i <= m; ++i) {
        for (int j = y; j <= n; ++j) {
            res = max(res, s[i][j] - s[i - x][j] - s[i][j - y] + s[i - x][j - y]);
        }
    }
    cout << res << endl;
    return 0;
}