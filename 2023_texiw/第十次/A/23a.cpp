// LIS 最长上升子序列 动态规划

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
int a[N]; // ai < 1e9
int f[N]; // f[i] 表示以 a[i] 结尾的 LIS
int ans = 0;
signed main()
{
    int n;
    // 10
    cin >> n;
    for (int i = 0; i < n; ++i) {
        // 0 5 7 1 9 4 6 2 8 3
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) { // f 初始化 1，都以自身为 LIS
        f[i] = 1;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[i] > a[j]) { // 上升性
                f[i] = max(f[i], f[j] + 1);
            }
        }
        ans = max(ans, f[i]);
    }
    cout << ans << endl;
    // 5
}