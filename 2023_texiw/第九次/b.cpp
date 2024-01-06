#include <bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    // 通过输入的times多维数组构造邻接矩阵
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, -1));
    for (auto &time : times) {
        graph[time[0]][time[1]] = time[2];
    }
    // 用dis来存储最短距离
    vector<int> dis(n + 1, INT_MAX);
    // 创建队列
    queue<int> Q;
    // 先将源点放入队列中，源点到源点的距离设置为0
    Q.push(k);
    dis[k] = 0;
    // while循环，当队列中没有元素跳出
    while (!Q.empty()) {
        int top = Q.front();
        Q.pop();
        for (int i = 1; i <= n; i++) {
            // 遍历所有点，从队首元素出发，如果存在路径，判断是否为最小值，如果是则修改dis数组元素
            if (graph[top][i] != -1 && graph[top][i] + dis[top] < dis[i]) {
                dis[i] = graph[top][i] + dis[top];
                Q.push(i); // 将下一个点放入队列，作为下次循环的起点
            }
        }
    }
    // 当队列中元素遍历完，最短距离数组dis已经完整。这时遍历数组取出最大值
    int max = 0;
    for (int i = 1; i <= n; i++) {
        if (max < dis[i]) {
            max = dis[i];
        }
    }
    return max == INT_MAX ? -1 : max;
}

int main()
{
    freopen("in.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> times(6007, vector<int>(3));
    int a, b, c;
    int i = 0;
    while (cin >> a >> b >> c) {
        times[i] = {a, b, c};
        ++i;
    }
    cout << networkDelayTime(times, n, k) << endl;
    return 0;
}