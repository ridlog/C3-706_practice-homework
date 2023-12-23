#include <bits/stdc++.h>
using namespace std;

// 图的顶点结构
struct Vertex {
    int id;
    int visited;
    vector<int> neighbors;
};

// 深度优先遍历
void dfs(vector<Vertex> &graph, int vertex)
{
    cout << vertex << " ";
    graph[vertex].visited = 1;

    for (int neighbor : graph[vertex].neighbors) {
        if (!graph[neighbor].visited) {
            dfs(graph, neighbor);
        }
    }
}

// 广度优先遍历
void bfs(vector<Vertex> &graph)
{
    queue<int> q;
    q.push(0);
    graph[0].visited = 2;

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        cout << vertex << " ";

        for (int neighbor : graph[vertex].neighbors) {
            if (graph[neighbor].visited != 2) {
                q.push(neighbor);
                graph[neighbor].visited = 2;
            }
        }
    }
}

int main()
{
    // freopen("in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;

    // 创建图的邻接表
    vector<Vertex> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].neighbors.push_back(v);
        graph[v].neighbors.push_back(u);
    }
    for (auto &vertex : graph) {
        sort(vertex.neighbors.begin(), vertex.neighbors.end(), less<int>());
    }

    int deletedVertex;
    cin >> deletedVertex;

    // 深度优先遍历
    dfs(graph, 0);
    cout << endl;

    // 删除给定顶点及其相关的边
    graph[deletedVertex].neighbors.clear();
    for (Vertex &vertex : graph) {
        for (int i = 0; i < vertex.neighbors.size(); i++) {
            if (vertex.neighbors[i] == deletedVertex) {
                vertex.neighbors.erase(vertex.neighbors.begin() + i);
                break;
            }
        }
    }
    // 广度优先遍历
    bfs(graph);
    cout << endl;

    return 0;
}
