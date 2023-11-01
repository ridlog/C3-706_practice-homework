// 直接模拟
#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 7;
int b[N][N];
int n, heri, veti;
void solve(int n)
{
    int i;
    // for (i = 1; i < n; ++i) {
    //     b[i][1] = i;
    // }
    // for (int j = 1; j < n; ++i, ++j) {
    //     b[n][j] = i;
    // }
    // for (int j = 1; j < n; ++i, ++j) {
    //     b[n - j + 1][n] = i;
    // }
    // for (int j = 1; j < n; ++i, ++j) {
    //     b[1][n - j + 1] = i;
    // }

    // int k = 0;
    // for (; k <= n / 2; ++k) {
    //     for (int j = 2 + k; j <= n - k; ++j) {
    //         b[j][1 + k] = i;
    //     }
    //     for (int j = 2 + k; j <= n - k; ++i, ++j) {
    //         b[n - k][j] = i;
    //     }
    //     for (int j = 2 + k; j <= n - k; ++i, ++j) {
    //         b[n - k - j + 1][n - k] = i;
    //     }
    //     for (int j = 2 + k; j <= n - k; ++i, ++j) {
    //         b[1 + k][n - k - j + 1] = i;
    //     }
    // }

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
        // for (int i = 1; i <= n; ++i) {
        //     for (int j = 1; j <= n; ++j) {
        //         cout << b[j][i] << ' ';
        //     }
        //     cout << '\n';
        // }
    }
    if (n & 1) {
        b[n / 2 + 1][n / 2 + 1] = n * n;
    }
}
signed main()
{
    cin >> n;
    solve(n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << b[j][i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}