#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int st[257];
signed main()
{
    freopen("in.txt", "r", stdin);
    cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        int u = s[i];
        if (!st[u]) {
            if (n) {
                st[u] = 1;
                --n;
            } else {
                st[u] = 2;
            }
        } else if (st[u] == 1) {
            ++n;
            st[u] = 0;
        } else {
            ++ans;
        }
    }
    if (ans)
        cout << ans << " customer(s) walked away." << endl;
    else
        cout << "All customers tanned successfully." << endl;
    return 0;
}