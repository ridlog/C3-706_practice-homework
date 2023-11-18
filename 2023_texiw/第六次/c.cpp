// 直接模拟
#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 7;
int b[N][N];
int n, heri, veti;
void solve(int n)
{
    int i;
    int k = 0;
    i = 1;
    for (; k <= n / 2; ++k) {
        for (int j = 1 + k; j < n - k; ++i, ++j) {
            b[j][1 + k] = i;
        }
        for (int j = 1 + k; j < n - k; ++i, ++j) {
            b[n - k][j] = i;
        }
        for (int j = 1 + k; j < n - k; ++i, ++j) {
            b[n - j + 1][n - k] = i;
        }
        for (int j = 1 + k; j < n - k; ++i, ++j) {
            b[1 + k][n - j + 1] = i;
        }
    }
    if (n & 1) {
        b[n / 2 + 1][n / 2 + 1] = n * n;
    }
}
signed main()
{
    freopen("in.txt", "r", stdin);
    cin >> n;
    solve(n);
    cout << "[\n";
    for (int i = 1; i <= n; ++i) {
        cout << '[';
        for (int j = 1; j <= n; ++j) {
            if (j != n)
                cout << b[j][i] << ',';
            else
                cout << b[j][i];
        }
        if (i != n)
            cout << "],\n";
        else
            cout << "]\n";
    }
    cout << ']';
    return 0;
}