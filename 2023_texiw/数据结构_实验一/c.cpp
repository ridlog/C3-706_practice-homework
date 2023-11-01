#include <bits/stdc++.h>
using namespace std;

const int N = 17;
int A[N][N], B[N][N];
int m1, m2, n1, n2, a1, a2;
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("in.txt", "r", stdin);
    freopen("abc.out", "w", stdout);
    cin >> m1 >> n1;
    for (int i = 1; i <= m1; ++i) {
        for (int j = 1; j <= n1; ++j) {
            cin >> A[i][j];
        }
    }
    cin >> m2 >> n2;
    for (int i = 1; i <= m2; ++i) {
        for (int j = 1; j <= n2; ++j) {
            cin >> B[i][j];
        }
    }
    cin >> a1 >> a2;

    for (int i = 1; i <= m1; ++i) {
        for (int j = 1; j <= m2; ++j) {
            if (A[i][a1] == B[j][a2]) {
                for (int p = 1; p <= n1; ++p)
                    cout << A[i][p] << ' ';
                for (int q = 1; q <= n2; ++q)
                    cout << B[j][q] << ' ';
                cout << '\n';
            }
        }
    }
    return 0;
}