#include <bits/stdc++.h>
using namespace std;

const int N = 17;
const int MaxCol = 17;
int m1, m2, n1, n2, a1, a2, x;

struct DataNode {
    int data[MaxCol];
    DataNode *next;
};
struct HNode {
    int Row, Col;
    DataNode *next;
    HNode() : next(NULL) {}
    HNode(int r, int c)
    {
        Row = r;
        Col = c;
        next = NULL;
    }
};
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("in.txt", "r", stdin);
    freopen("abc.out", "w", stdout);

    HNode *hA = new HNode;
    HNode *hB = new HNode;
    DataNode *tA = new DataNode;
    DataNode *tB = new DataNode;
    hA->next = tA, hB->next = tB;

    cin >> m1 >> n1;
    hA->Row = m1, hA->Col = n1;
    for (int i = 1; i <= m1; ++i) {
        for (int j = 1; j <= n1; ++j) {
            cin >> tA->data[j];
        }
        DataNode *tmp = new DataNode;
        tA->next = tmp;
        tA = tmp;
    }
    cin >> m2 >> n2;
    hB->Row = m2, hB->Col = n2;
    for (int i = 1; i <= m2; ++i) {
        for (int j = 1; j <= n2; ++j) {
            cin >> tB->data[j];
        }
        DataNode *tmp = new DataNode;
        tB->next = tmp;
        tB = tmp;
    }
    cin >> a1 >> a2;

    for (auto itA = hA->next; itA->next != NULL; itA = itA->next) {
        for (auto itB = hB->next; itB->next != NULL; itB = itB->next) {
            if (itA->data[a1] == itB->data[a2]) {
                for (int p = 1; p <= n1; ++p)
                    cout << itA->data[p] << ' ';
                for (int q = 1; q <= n2; ++q)
                    cout << itB->data[q] << ' ';
                cout << '\n';
            }
        }
    }
    return 0;
}