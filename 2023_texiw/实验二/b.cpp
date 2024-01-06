#include <fstream>
#include <iostream>
#include <map>
using namespace std;

struct TreeNode {
    char value;
    TreeNode *left;
    TreeNode *right;
};

// 递归构建Huffman编码树
TreeNode *buildHuffmanTree(map<char, string> &huffmanCodes)
{
    TreeNode *root = new TreeNode();
    root->value = '\0';
    root->left = nullptr;
    root->right = nullptr;

    for (const auto &pair : huffmanCodes) {
        char ch = pair.first;
        const string &code = pair.second;

        TreeNode *currentNode = root;
        for (char bit : code) {
            if (bit == '0') {
                if (currentNode->left == nullptr) {
                    currentNode->left = new TreeNode();
                    currentNode->left->value = '\0';
                    currentNode->left->left = nullptr;
                    currentNode->left->right = nullptr;
                }
                currentNode = currentNode->left;
            } else if (bit == '1') {
                if (currentNode->right == nullptr) {
                    currentNode->right = new TreeNode();
                    currentNode->right->value = '\0';
                    currentNode->right->left = nullptr;
                    currentNode->right->right = nullptr;
                }
                currentNode = currentNode->right;
            }
        }

        currentNode->value = ch;
    }

    return root;
}

// 解码Huffman编码文件
void decodeHuffmanFile(const string &filename, TreeNode *root)
{
    ifstream file(filename);
    if (!file) {
        cout << "无法打开文件：" << filename << endl;
        return;
    }

    TreeNode *currentNode = root;

    char bit;
    while (file >> bit) {
        if (bit == '0') {
            currentNode = currentNode->left;
        } else if (bit == '1') {
            currentNode = currentNode->right;
        }

        if (currentNode->left == nullptr && currentNode->right == nullptr) {
            cout << currentNode->value;
            currentNode = root;
        }
    }

    file.close();
}

int main()
{
    int n;
    cin >> n;

    map<char, string> huffmanCodes;
    for (int i = 0; i < n; i++) {
        char ch;
        string code;
        cin >> ch >> code;
        huffmanCodes[ch] = code;
    }

    TreeNode *root = buildHuffmanTree(huffmanCodes);

    decodeHuffmanFile("in.txt", root);

    return 0;
}