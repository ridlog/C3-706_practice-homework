#include <iostream>
#include <malloc.h>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef struct BinTreeNode {
    char data;
    struct BinTreeNode *lchild;
    struct BinTreeNode *rchild;
} BinTreeNode, *BinTree;

int FindComma(string &s, int len)
{
    int match = 0;
    int i;
    for (i = 0; i < len; i++) {
        if (s[i] == '(')
            ++match;
        else if (s[i] == ')')
            --match;
        if (match == 0 && s[i] == ',')
            break;
    }
    return i;
}
BinTree Create(string s, int len)
{
    if (s[0] == '#')
        return NULL;
    BinTree root = (BinTree)malloc(sizeof(BinTreeNode));
    root->data = s[0];
    if (len == 1) {
        root->lchild = NULL;
        root->rchild = NULL;
    } else {
        s = s.substr(2);
        int commaPos = FindComma(s, len - 2);
        root->lchild = Create(s, commaPos);
        root->rchild = Create(s.substr(commaPos + 1), len - 3 - commaPos - 1);
    }
    return root;
}
void LeftLeaves(BinTree T)
{
    if (T == NULL)
        return;
    BinTree p = T;
    if (p->lchild)
        LeftLeaves(p->lchild);
    if (p->rchild)
        LeftLeaves(p->rchild);
    if (!p->lchild && !p->rchild)
        printf("%c ", p->data);
}
void RightLeaves(BinTree T)
{
    queue<BinTree> q;
    if (T == NULL)
        return;
    BinTree p = T;
    q.push(p);
    while (!q.empty()) {
        p = q.front();
        q.pop();
        if (!p->rchild && !p->lchild)
            printf("%c ", p->data);
        if (p->rchild)
            q.push(p->rchild);
        if (p->lchild)
            q.push(p->lchild);
    }
    printf("\n");
}
void LevelPrint(BinTree T)
{
    queue<BinTree> q;
    if (T == NULL)
        return;
    BinTree p = T;
    q.push(p);
    while (!q.empty()) {
        p = q.front();
        q.pop();
        if (p->data != '#')
            printf("%c ", p->data);
        if (p->rchild)
            q.push(p->rchild);
        if (p->lchild)
            q.push(p->lchild);
    }
    printf("\n");
}
int main()
{
    freopen("in.txt", "r", stdin);
    string str;
    cin >> str;
    BinTree root;
    root = (BinTree)malloc(sizeof(BinTreeNode));
    root = Create(str, str.size());
    LeftLeaves(root);
    puts("");
    RightLeaves(root);
    LevelPrint(root);
    return 0;
}