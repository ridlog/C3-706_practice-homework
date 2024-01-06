#include <cctype>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
    char value;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : left(NULL), right(NULL) {}
};

// 判断字符是否为运算符
bool isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// 判断运算符的优先级
int getPriority(char op)
{
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

stack<TreeNode *> nodeStack;
stack<char> opStack;
// 构建表达式树
TreeNode *buildExpressionTree(string &expression)
{
    stack<TreeNode *> nodeStack;
    stack<char> opStack;

    for (int i = 0; i < expression.length(); i++) {
        char ch = expression[i];
        if (isspace(ch) || ch == '=') {
            continue;
        }

        if (ch == '(') {
            opStack.push(ch);
        } else if (isdigit(ch)) {
            string numStr;
            while (i < expression.length() && isdigit(expression[i])) {
                numStr += expression[i];
                i++;
            }
            i--;

            TreeNode *node = new TreeNode();
            node->value = stoi(numStr);
            node->left = nullptr;
            node->right = nullptr;
            nodeStack.push(node);
        } else if (isOperator(ch)) {
            while (!opStack.empty() && opStack.top() != '(' &&
                   getPriority(opStack.top()) >= getPriority(ch)) {
                TreeNode *node = new TreeNode();
                node->value = opStack.top();
                opStack.pop();
                node->right = nodeStack.top();
                nodeStack.pop();
                node->left = nodeStack.top();
                nodeStack.pop();

                nodeStack.push(node);
            }
            opStack.push(ch);
        } else if (ch == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                TreeNode *node = new TreeNode();
                node->value = opStack.top();
                opStack.pop();
                node->right = nodeStack.top();
                nodeStack.pop();
                node->left = nodeStack.top();
                nodeStack.pop();

                nodeStack.push(node);
            }
            opStack.pop(); // 弹出左括号
        }
    }

    while (!opStack.empty()) {
        TreeNode *node = new TreeNode();
        node->value = opStack.top();
        opStack.pop();
        node->right = nodeStack.top();
        nodeStack.pop();
        node->left = nodeStack.top();
        nodeStack.pop();

        nodeStack.push(node);
    }

    return nodeStack.top();
}

// 后序遍历表达式树并计算结果
int evaluateExpressionTree(TreeNode *root)
{
    if (root == nullptr) {
        return 0;
    }

    if (root->left == nullptr && root->right == nullptr) {
        return root->value;
    }

    int leftResult = evaluateExpressionTree(root->left);
    int rightResult = evaluateExpressionTree(root->right);

    switch (root->value) {
    case '+':
        return leftResult + rightResult;
    case '-':
        return leftResult - rightResult;
    case '*':
        return leftResult * rightResult;
    case '/':
        return leftResult / rightResult;
    default:
        return 0;
    }
}

void printValue(char ch)
{
    if (!isOperator(ch)) {
        std::cout << (int)ch << '#';
    } else
        std::cout << ch;
}

// 前序遍历表达式树
void preorderTraversal(TreeNode *root)
{
    if (root == nullptr) {
        return;
    }

    printValue(root->value);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// 中序遍历表达式树
void inorderTraversal(TreeNode *root)
{
    if (root == nullptr) {
        return;
    }

    inorderTraversal(root->left);
    printValue(root->value);
    inorderTraversal(root->right);
}

// 后序遍历表达式树
void postorderTraversal(TreeNode *root)
{
    if (root == nullptr) {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printValue(root->value);
}

// 层次遍历表达式树
void levelOrderTraversal(TreeNode *root)
{
    if (root == nullptr) {
        return;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop();

        printValue(node->value);

        if (node->left != nullptr) {
            q.push(node->left);
        }
        if (node->right != nullptr) {
            q.push(node->right);
        }
    }
}

int main()
{
    // freopen("in.txt", "r", stdin);
    string expression;
    getline(cin, expression);
    TreeNode *root = buildExpressionTree(expression);
    // std::cout << "前序遍历结果：";
    preorderTraversal(root);
    std::cout << endl;

    // std::cout << "中序遍历结果：";
    inorderTraversal(root);
    std::cout << endl;

    // std::cout << "后序遍历结果：";
    postorderTraversal(root);
    std::cout << endl;

    // std::cout << "层次遍历结果：";
    levelOrderTraversal(root);
    std::cout << endl;

    int result = evaluateExpressionTree(root);
    // std::cout << "表达式结果： " << result << endl;
    std::cout << result << endl;

    return 0;
}