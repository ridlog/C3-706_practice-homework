#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
#define pi pair<int, int>
int n, x;
string op;
char ag1, ag2;
pi a[N], b[N];
int ia, ib, id;
bool cmp(pi &a, pi &b)
{
    return a.second < b.second;
}
signed main()
{
    freopen("in.txt", "r", stdin);
    cin >> n;
    while (n--) {
        cin >> op >> ag1;
        if (op == "push") {
            cin >> x;
            if (ag1 == 'A')
                a[++ia] = {x, ++id};
            else
                b[++ib] = {x, ++id};
        } else if (op == "pop") {
            if (ag1 == 'A')
                cout << a[ia--].first << '\n';
            else
                cout << b[ib--].first << '\n';
        } else {
            cin >> ag2;
            if (ag1 == 'A') {
                for (int i = 1; i <= ib; ++i) {
                    a[++ia] = b[i];
                }
                ib = 0;
                sort(a + 1, a + ia + 1, cmp);
            } else {
                for (int i = 1; i <= ia; ++i)
                    b[++ib] = a[i];
                ia = 0;
                sort(b + 1, b + ib + 1, cmp);
            }
        }
    }
    return 0;
}