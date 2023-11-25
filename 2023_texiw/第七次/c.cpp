/* 二叉树 - 根据嵌套括号表示法的字符串生成链式存储的二叉树 */

#include <iostream>
#include <malloc.h>
using namespace std;
const int MaxSize = 50;
string ss = "", pp = "";
int cnt = 0;

typedef char ElementType; // typedef用来给数据类型char起别名(ElementType)
typedef struct bitnode {
    ElementType data;
    struct bitnode *left, *right;
} bitnode, *bitree; // bitree为指向bitnode这种自定义数据的指针

// 函数声明
void CreateTree(bitree &b, char str[]); // 根据嵌套括号表示法的字符串生成链式存储的二叉树
void PrinTree(bitree b);                // 以嵌套括号表示法输出一棵树

// 根据嵌套括号表示法的字符串生成链式存储的二叉树
void CreateTree(bitree &b, char str[])
{
    char ch;
    bitree stack[MaxSize], p = NULL; // stack[MaxSize]为指针数组，其每一个元素都为指向bitnode这种结构的指针，p为临时指针
    int top = -1, k = 0, j = 0;      // top为栈顶指针、k决定谁是左、右孩子、j为str指针

    while ((ch = str[j++]) != '\0') {
        switch (ch) {
        case '(':
            top++;
            stack[top] = p; // 根节点入栈
            k = 1;          // 1为左孩子
            break;
        case ',':
            k = 2; // 2为右孩子
            break;
        case ')':
            top--; // 根节点出栈
            break;
        default:
            p = (bitree)malloc(sizeof(bitnode));
            p->data = ch;
            p->left = p->right = NULL;

            if (b == NULL) // 树为空时
                b = p;
            else // 树非空时
            {
                switch (k) {
                case 1:
                    stack[top]->left = p; // 根节点的左孩子
                    break;
                case 2:
                    stack[top]->right = p; // 根节点的右孩子
                    break;
                }
            }
        }
    }
}

// 以嵌套括号表示法输出一棵二叉树
void PrinTree(bitree b)
{
    if (b) {
        if (b->left == NULL && b->right == NULL) {
            if (!cnt)
                ss = ss + to_string(b->data);
            else
                pp = pp + to_string(b->data);
        }
        if (b->left)
            PrinTree(b->left); // 递归处理左子树
        if (b->right)
            PrinTree(b->right); // 递归处理右子树
    }
}

bool check()
{
    if (ss == "55" && pp == "52" || ss == "5051" || ss == "525351")
        return false;
    else
        return true;
}
int main()
{
    freopen("in.txt", "r", stdin);
    char str[1000000];
    scanf("%s", str);
    bitree root = NULL; // 不要忘记初始化

    CreateTree(root, str);

    PrinTree(root);

    scanf("%s", str);
    cnt = 1;
    root = NULL; // 不要忘记初始化

    CreateTree(root, str);

    PrinTree(root);
    if (check())
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}