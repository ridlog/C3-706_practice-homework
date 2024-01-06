#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int a[N], n;
int tmp[N];
void merge_sort(int q[], int l, int r)
{
    if (l >= r)
        return;

    int mid = l + r >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (q[i] < q[j])
            tmp[k++] = q[i++];
        else
            tmp[k++] = q[j++];

    while (i <= mid)
        tmp[k++] = q[i++];
    while (j <= r)
        tmp[k++] = q[j++];

    for (i = l, j = 0; i <= r; i++, j++)
        q[i] = tmp[j];
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
    merge_sort(a, 1, n);
    for (int j = 1; j <= n; ++j)
        cout << a[j] << ' ';
    return 0;
}