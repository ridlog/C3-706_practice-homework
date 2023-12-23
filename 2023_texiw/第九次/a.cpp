#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
const int inf = 0x3f3f3f;
int a[maxn][maxn], dis[maxn][maxn];
int main()
{
    freopen("in.txt", "r", stdin);
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                a[i][j] = a[j][i] = dis[i][j] = dis[j][i] = inf;
        while (m--) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            if (w < dis[u][v])
                a[u][v] = a[v][u] = dis[u][v] = dis[v][u] = w;
        }
        int ans = inf;
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i < k; i++)
                for (int j = i + 1; j < k; j++) // 这里得是i+1,防止重复
                    ans = min(ans, dis[i][j] + a[i][k] + a[k][j]);
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
        if (ans == inf)
            puts("It's impossible.");
        else
            printf("%d\n", ans);
    }
    return 0;
}
