#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int a[N], n, k, x;
string s;
signed main()
{
    freopen("in.txt", "r", stdin);
    int i = 0;
    getline(cin, s);
    cin >> k;
    stringstream ss(s);
    while (ss >> x) {
        a[i++] = x, ++n;
    }
    for (int j = 0; j < n; ++j) {
        for (int m = j + 1; m < n; ++m) {
            if (a[m] + a[j] == k) {
                cout << j << ' ' << m << endl;
                return 0;
            }
        }
    }
    cout << "-1 -1" << endl;
    return 0;
}