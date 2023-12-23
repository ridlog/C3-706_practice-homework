#include <algorithm>
#include <iostream>
using namespace std;
int n, a[1000001], ans;
bool f(int num)
{
    int con = 0, t = n * (n - 1) / 4;
    for (int i = 0; i < n; i++)
        con += n - (lower_bound(a, a + n, a[i] + num) - a);
    if (con > t)
        return 1;
    else
        return 0;
}
int main()
{
    freopen("in.txt", "r", stdin);
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        int l = 0, r = a[n - 1] - a[0], mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (f(mid) == 1) {
                ans = mid;
                l = mid + 1;
            } else
                r = mid - 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}