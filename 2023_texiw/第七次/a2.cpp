#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0x3f3f3f3f), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *buildTreeFromString(const string &str, int &index)
{
    if (index >= str.length()) {
        return NULL;
    }
    // 解析当前节点的值
    bool hasLeft = false;
    int val = 0;
    int sign = 1;
    if (str[index] == '-') {
        sign = -1;
        index++;
    }
    while (index < str.length() && isdigit(str[index])) {
        hasLeft = true;
        val = val * 10 + (str[index] - '0');
        index++;
    }
    val *= sign;

    // 创建当前节点
    TreeNode *node = hasLeft ? new TreeNode(val) : NULL;

    // 解析左子树
    if (index < str.length() && str[index] == '(') {
        index++;
        node->left = buildTreeFromString(str, index);
        // 解析右子树
        if (index < str.length() && str[index] == ',') {
            index++;
            node->right = buildTreeFromString(str, index);
        }

        // 跳过右括号
        if (index < str.length() && str[index] == ')') {
            index++;
        }
    }

    return node;
}

TreeNode *stringToTree(const string &str)
{
    int index = 0;
    return buildTreeFromString(str, index);
}

void getLeafNodes(TreeNode *root, vector<int> &result)
{
    if (root == NULL) {
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        result.push_back(root->val);
    }

    getLeafNodes(root->left, result);
    getLeafNodes(root->right, result);
}

vector<int> getLeafNodesLeftToRight(TreeNode *root)
{
    vector<int> result;
    getLeafNodes(root, result);
    return result;
}
void getLeafNodes2(TreeNode *root, vector<int> &result)
{
    if (root == NULL) {
        return;
    }

    getLeafNodes2(root->right, result);
    getLeafNodes2(root->left, result);

    if (root->left == NULL && root->right == NULL) {
        result.push_back(root->val);
    }
}

vector<int> getLeafNodesRightToLeft(TreeNode *root)
{
    vector<int> result;
    getLeafNodes2(root, result);
    return result;
}

vector<int> getAllNodesRightToLeft(TreeNode *root)
{
    vector<int> result;
    if (root == NULL) {
        return result;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        stack<int> level;

        for (int i = 0; i < size; i++) {
            TreeNode *node = q.front();
            q.pop();

            level.push(node->val);

            if (node->left != NULL) {
                q.push(node->left);
            }

            if (node->right != NULL) {
                q.push(node->right);
            }
        }

        while (!level.empty()) {
            result.push_back(level.top());
            level.pop();
        }
    }

    return result;
}
void printTree(TreeNode *root, string prefix, bool isLeft)
{
    if (root == NULL) {
        return;
    }

    cout << prefix;
    cout << (isLeft ? "├──" : "└──");
    cout << root->val << endl;

    printTree(root->left, prefix + (isLeft ? "│   " : "    "), true);
    printTree(root->right, prefix + (isLeft ? "│   " : "    "), false);
}
void printDemo()
{
    // 创建二叉树
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(3);
    root->right = new TreeNode(5);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    printTree(root, "", false);
}
string s;
int main()
{
    freopen("in.txt", "r", stdin);
    cin >> s;
    TreeNode *root = stringToTree(s);
    // printDemo();
    // printTree(root, "", false);

    // 获取按从左到右顺序输出的叶子节点
    vector<int> leafNodesLeftToRight = getLeafNodesLeftToRight(root);

    // 输出按从左到右顺序输出的叶子节点
    for (int i = 0; i < leafNodesLeftToRight.size(); i++) {
        cout << leafNodesLeftToRight[i] << " ";
    }
    cout << endl;

    // 获取按从右到左顺序输出的叶子节点
    vector<int> leafNodesRightToLeft = getLeafNodesRightToLeft(root);

    // 输出按从右到左顺序输出的叶子节点
    for (int i = 0; i < leafNodesRightToLeft.size(); i++) {
        cout << leafNodesRightToLeft[i] << " ";
    }
    cout << endl;

    // 获取按要求输出的所有节点
    vector<int> allNodesRightToLeft = getAllNodesRightToLeft(root);

    // 输出按要求输出的所有节点
    for (int i = 0; i < allNodesRightToLeft.size(); i++) {
        cout << allNodesRightToLeft[i] << " ";
    }
    cout << endl;
    return 0;
}