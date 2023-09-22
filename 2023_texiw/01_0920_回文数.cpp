#include <bits/stdc++.h>
using namespace std;

int n;

void work(int n)
{
    string s = to_string(n);
    int i = 0, j = s.size() - 1;
    do {
        if (s[i] != s[j]) {
            cout << 0;
            return;
        }
        ++i, --j;
    } while (i < j);
    cout << 1;
}
signed main()
{
    freopen("in.txt", "r", stdin);
    cin >> n;
    work(n);
    return 0;
}