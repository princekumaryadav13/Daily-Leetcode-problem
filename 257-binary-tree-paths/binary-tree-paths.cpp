/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, vector<string>& ans, string sum) {
        if (!root)
            return;

        if (!sum.empty()) {
            sum += "->";
        }
        sum += to_string(root->val);

        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(sum);
        }
        if (root->left) {
            dfs(root->left, ans, sum);
        }
        if (root->right) {
            dfs(root->right, ans, sum);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string sum = "";
        dfs(root, ans, sum);
        return ans;
    }
};