#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 2e9;
const int N = 1e3 + 7;
int vis[N];
pair<int, int> d[N];
#define aa first
#define bb second
struct edge {
    int id, v, w;
};
vector<edge> e[N];
vector<int> ids;
int n, m;
typedef long long i64;
i64 ans, cnt;

bool solve(int s)
{
    for (int i = 0; i <= n; ++i)
        d[i].aa = INF;
    d[s].aa = 0;
    for (int i = 1; i <= n; ++i) {
        int u = 0;
        for (int j = 1; j <= n; ++j) {
            if (!vis[j] && d[j] < d[u])
                u = j;
        }
        vis[u] = 1;
        ans += d[u].aa;
        if (d[u].bb)
            ids.push_back(d[u].bb);
        if (d[u].aa != INF)
            ++cnt;
        for (auto [id, v, w] : e[u]) {
            if (d[v].aa > w)
                d[v] = {w, id};
        }
    }
    return cnt == n;
}
signed main()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int id, u, v, w;
        cin >> id >> u >> v >> w;
        u += 1, v += 1;
        e[u].push_back({id, v, w});
        e[v].push_back({id, u, w});
    }
    solve(1);
    cout << ans << '\n';
    sort(ids.begin(), ids.end());
    for (auto &v : ids) {
        cout << v << ' ';
    }
    return 0;
}