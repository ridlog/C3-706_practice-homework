#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to insert a new node into the Binary Search Tree
TreeNode *insert(TreeNode *root, int val)
{
    if (root == NULL)
        return new TreeNode(val);

    if (val <= root->val)
        root->left = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);

    return root;
}

// Function to perform an inorder traversal of the Binary Search Tree
void inorderTraversal(TreeNode *root, vector<int> &inorder)
{
    if (root == NULL)
        return;

    inorderTraversal(root->left, inorder);
    inorder.push_back(root->val);
    inorderTraversal(root->right, inorder);
}

// Function to perform a binary search on the inorder traversal result
int binarySearch(vector<int> &inorder, int target)
{
    int left = 0;
    int right = inorder.size() - 1;
    int count = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (inorder[mid] == target)
            return count + 1;
        else if (inorder[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;

        count++;
    }

    return count;
}

// Function to search for a value in the Binary Search Tree
int search(TreeNode *root, int target, int count)
{
    if (root == NULL)
        return count;

    if (root->val == target)
        return count + 1;
    else if (root->val < target)
        return search(root->right, target, count + 1);
    else
        return search(root->left, target, count + 1);
}

int main()
{
    int n;
    cin >> n;

    TreeNode *root = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    int target;
    cin >> target;

    int bstComparison = search(root, target, 0);

    vector<int> inorder;
    inorderTraversal(root, inorder);

    int binarySearchComparison = binarySearch(inorder, target);
    // << "BST Comparison: "
    cout << bstComparison << endl;

    // cout << "Inorder Traversal: ";
    for (int i = 0; i < inorder.size(); i++) {
        cout << inorder[i] << " ";
    }
    cout << endl;
    // << "Binary Search Comparison: "
    cout << binarySearchComparison << endl;

    return 0;
}