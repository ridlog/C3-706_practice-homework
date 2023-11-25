#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 找到start--end之间数组的最大值所在的下标
int find(vector<int> &nums, int start, int end)
{
    int index = start;
    for (int i = start; i < end; i++) {
        if (nums[index] < nums[i])
            index = i;
    }
    return index;
}
// 递归进行建树
TreeNode *dfs(vector<int> &nums, int begin, int end)
{
    // 左侧或者右侧没有元素的情况下（或者理解为到达数组的终点）
    if (begin == end)
        return NULL;
    // 找到当前数组最大值的下标
    int part = find(nums, begin, end);
    TreeNode *root = new TreeNode(nums[part]);
    // 有点像二分搜索
    root->left = dfs(nums, begin, part);
    root->right = dfs(nums, part + 1, end);
    return root;
}
TreeNode *constructMaximumBinaryTree(vector<int> &nums)
{
    return dfs(nums, 0, nums.size());
}
void preorderTraversal(TreeNode *root, string &result)
{
    if (root == NULL) {
        return;
    }

    // 输出当前节点的值
    result += to_string(root->val);

    // 如果左子树或右子树不为空，则输出左括号
    if (root->left != NULL || root->right != NULL) {
        result += "(";
    }

    // 递归遍历左子树
    preorderTraversal(root->left, result);

    // 如果左子树为空且右子树不为空，则输出空括号
    if (root->right != NULL) {
        result += ",";
    }

    // 递归遍历右子树
    preorderTraversal(root->right, result);

    // 如果左子树或右子树不为空，则输出右括号
    if (root->left != NULL || root->right != NULL) {
        result += ")";
    }
}
vector<int> nums;
int x;

int main()
{
    freopen("in.txt", "r", stdin);
    while (scanf("%d", &x) != EOF) {
        nums.push_back(x);
    }
    TreeNode *root = constructMaximumBinaryTree(nums);
    string res;
    preorderTraversal(root, res);
    cout << res << endl;
    return 0;
}