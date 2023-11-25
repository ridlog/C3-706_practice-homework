#include <cmath>
#include <iostream>
#include <vector>
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long
#define pii pair<int, int>
using namespace std;
int t, n, l, r, root, lgN;
int P[10010][100], D[10010], from[10010];
vector<int> nxt[10010];
// Parents
void computeP()
{
    for (int i = 0; i < lgN; i++) {
        for (int j = 1; j <= n; j++) {
            if (P[j][i] == -1)
                P[j][i + 1] = -1;
            else
                P[j][i + 1] = P[P[j][i]][i];
        }
    }
}

bool vis[10010];
void computeD(int px, int h)
{
    D[px] = h;
    vis[px] = true;
    for (int i = 0; i < nxt[px].size(); i++) {
        if (!vis[nxt[px][i]])
            computeD(nxt[px][i], h + 1);
    }
}

// Distance
int LCA(int u, int v)
{
    if (D[u] > D[v])
        swap(u, v);
    int dis = D[v] - D[u];
    for (int i = lgN; i >= 0; i--) {
        if (dis & (1 << i))
            v = P[v][i];
    }
    if (u == v)
        return v;
    for (int i = lgN; i >= 0; i--) {
        if (P[u][i] != P[v][i]) {
            u = P[u][i];
            v = P[v][i];
        }
    }
    return P[v][0];
}
int logbase(double a, double base)
{
    return log(a) / log(base);
}
void init()
{
    lgN = logbase(n, 2);
    for (int i = 0; i < 10010; i++) {
        for (int j = 0; j < lgN; j++) {
            P[i][j] = -1;
        }
        D[i] = 0;
        from[i] = -1;
        vis[i] = false;
        nxt[i].clear();
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    IOS;
    t = 1;
    while (t--) {
        cin >> n;
        init();
        for (int i = 0, x, y; i < n - 1; i++) {
            cin >> x >> y;
            P[y][0] = x;
            from[y] = x;
            nxt[x].push_back(y);
        }
        for (int i = 1; i <= n; i++) {
            if (from[i] == -1) {
                root = i;
                break;
            }
        }
        computeP();
        computeD(root, 0);
        cin >> l >> r;
        cout << LCA(l, r) << "\n";
    }
    return 0;
}
