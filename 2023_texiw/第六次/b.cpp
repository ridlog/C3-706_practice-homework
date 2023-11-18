#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
int n, ans;
int pos[N], c[N], p[N], q[N];
void dfs(int i)
{
    if (i > n) {
        ++ans;
        return;
    }
    for (int j = 1; j <= n; ++j) {
        if (c[j] || p[i + j] || q[i - j + n])
            continue;
        pos[i] = j;
        c[j] = p[i + j] = q[i - j + n] = 1;
        dfs(i + 1);
        c[j] = p[i + j] = q[i - j + n] = 0;
    }
}
signed main()
{
    freopen("in.txt", "r", stdin);
    cin >> n;
    dfs(1);
    cout << ans << endl;
    return 0;
}