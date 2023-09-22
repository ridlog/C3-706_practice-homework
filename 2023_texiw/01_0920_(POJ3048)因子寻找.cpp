#include <bits/stdc++.h>
using namespace std;

const int N = 2e4 + 7;
int n, x, st[N], maxd = -1, ans;

signed main()
{
    freopen("in.txt", "r", stdin);
    st[1] = 1;
    for (int i = 2; i < N; ++i) {
        if (!st[i])
            for (int j = i; j < N; j += i)
                st[j] = i;
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (st[x] > maxd) {
            maxd = st[x];
            ans = x;
        }
    }
    cout << ans;
    return 0;
}