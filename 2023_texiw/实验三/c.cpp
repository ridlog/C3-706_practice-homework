#include <bits/stdc++.h>
using namespace std;

vector<string> st;
signed main()
{
    int n, m;
    cin >> n >> m;
    string s;
    for (int i = 0; i < m; ++i) {
        cin >> s;
        st.push_back(s);
    }
    sort(st.begin(), st.end(), [&](const string &s1, const string &s2) {
        int a = 0, b = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (s1[j] < s1[i])
                    ++a;
                if (s2[j] < s2[i])
                    ++b;
            }
        }
        return a < b;
    });
    for (auto &v : st)
        cout << v << '\n';
}