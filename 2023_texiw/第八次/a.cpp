#include <iostream>
#include <stack>
using namespace std;

struct node {
    int value;
    node *left;
    node *right;
    node(int v) : value(v), left(NULL), right(NULL) {}
};

node *RebuildTree(int *Prec, int *Inorder, int n)
{
    if (!Prec || !Inorder || n < 1)
        return NULL;
    node *root = new node(Prec[0]);
    int i = 0;
    for (; i < n && Inorder[i] != Prec[0]; ++i)
        ;

    root->left = RebuildTree(Prec + 1, Inorder, i);
    root->right = RebuildTree(Prec + 1 + i, Inorder + 1 + i, n - i - 1);

    return root;
}

void Print(node *root)
{
    node *p = root;
    stack<node *> st;
    node *pre = NULL; // pre表示最近一次访问的结点
    if (!p)
        return;
    while (p || !st.empty()) {
        while (p) // 沿着左孩子方向走到最左下
        {
            st.push(p);
            p = p->left;
        }
        p = st.top();                     // 获取栈顶元素
        if (!p->right || p->right == pre) // 如果p没有右孩子或者其右孩子刚刚被访问过.小窍门if (!p)表示如果p为空
        {
            st.pop();
            if (p != root)
                cout << p->value << ' ';
            else
                cout << p->value << endl;
            pre = p;  // 最近一次访问的节点是p
            p = NULL; // 使下一次循环不再执行p节点以下的压栈操作
        } else
            p = p->right;
    }
}

void Del(node *root)
{
    if (!root)
        return;
    Del(root->left);
    Del(root->right);
    delete root;
}
int main()
{
    freopen("in.txt", "r", stdin);
    int Prec[1005];
    int Inorder[1005];
    int n, i;
    node *root = NULL;
    while (cin >> n) {
        for (i = 0; i < n; ++i)
            cin >> Prec[i];
        for (i = 0; i < n; ++i)
            cin >> Inorder[i];
        root = RebuildTree(Prec, Inorder, n);
        Print(root);
        Del(root);
    }
    return 0;
}