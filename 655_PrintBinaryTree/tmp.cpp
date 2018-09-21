#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>

using  namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

void goAlongLeftBranch(TreeNode* node, stack<TreeNode*> &s) {
    while (node)
    {
        s.push(node);
        if (node->left == nullptr && node->right)
            s.push(nullptr);
        node = node->left;
    }
}

vector<TreeNode*> inOrderTrave(TreeNode *root) {
    if (root == nullptr)
        return vector<TreeNode*>();
    stack<TreeNode*> s;
    vector<TreeNode*> res;
    goAlongLeftBranch(root, s);
    while (!s.empty()) {
        TreeNode* node = s.top();
        s.pop();
        res.push_back(node);
        goAlongLeftBranch(node, s);
    }
    return res;
}

vector<vector<string>> printTree(TreeNode* root) {
    if (root == nullptr)
        return vector<vector<string>>();
    queue<TreeNode*> que;
    int cur = 1, next = 0;
    TreeNode *p = root;
    que.push(p);
    int height = 0;
    vector<vector<string>> tmp;
    vector<string> ttmp;
    tmp.push_back(vector<string>{to_string(root->val)});
    while (!que.empty()) {
        TreeNode *node = que.front();
        que.pop();
        --cur;
        if (node->left) {
            ++next;
            que.push(node->left);
            ttmp.push_back(to_string(node->left->val));
        } else {
            ttmp.push_back(string("#"));
        }
        if (node->right) {
            ++next;
            que.push(node->right);
            ttmp.push_back(to_string(node->right->val));
        } else {
            ttmp.push_back(string("#"));
        }
        if (cur == 0) {
            tmp.push_back(ttmp);
            ttmp.erase(ttmp.begin(), ttmp.end());
            ++height;
            cur = next;
            next = 0;
        }
    }
    vector<TreeNode*> inOrder = inOrderTrave(root);
    int col = 1;
    for (int i = 1; i < height; ++i)
        col <<= 1;
    col = 2 * col - 1;
    vector<vector<string>> res(height, vector<string>(col));
    // 计算下标
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < tmp[i].size(); ++j)
        {
            if (tmp[i][j] != "#")
            {
                int index = rpw + 2*j;
                if (j >= pw/2)
                    index = (col/2)*2 - index;
                res[i][index] = tmp[i][j];
            }
        }
    }
    return res;
}

//int main() {
//
//    cout << pow(2, 3) << endl;
//
//    return 0;
//}