#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int a[N], n;

void qsort(int l, int r)
{
    if (l >= r)
        return;
    int m = a[(l + r) >> 1], i = l - 1, j = r + 1;
    while (i < j) {
        do
            ++i;
        while (a[i] < m);
        do
            --j;
        while (a[j] > m);
        if (i < j)
            swap(a[i], a[j]);
    }
    qsort(l, j), qsort(j + 1, r);
}
signed main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int i = 1;
    int x;
    while (scanf("%d", &x)) {
        a[i++] = x;
        char c = cin.get();
        if (c != ' ') {
            break;
        }
    }
    n = i - 1;
    qsort(1, n);
    for (int j = 1; j <= n; ++j)
        cout << a[j] << ' ';
    return 0;
}