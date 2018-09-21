#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

int treeHeight(TreeNode * root) {
    if (root == nullptr)
        return 0;
    return max(treeHeight(root->left), treeHeight(root->right)) + 1;
}

void fillTable(TreeNode *root, int level, int l, int r, vector<vector<string>> &res) {
    if (root == nullptr)
        return ;
    int m = l + (r - l) / 2;
    res[level][m] = to_string(root->val);
    fillTable(root->left, level+1, l, m, res);
    fillTable(root->right, level+1, m+1, r, res);
}

vector<vector<string>> printTree(TreeNode* root) {
    if (root == nullptr)
        return vector<vector<string>>();
    int h = treeHeight(root);
    int w = pow(2, h) - 1;
    vector<vector<string>> res(h, vector<string>(w));
    fillTable(root, 0, 0, w, res);
    return res;
}

