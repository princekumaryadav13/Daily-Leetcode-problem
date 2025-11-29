/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, int targetSum, vector<int> currentpath, vector<vector<int>>& path, int curr) {
        if (!root) return;

        // ✅ Push the integer value, NOT the pointer
        currentpath.push_back(root->val);
        curr += root->val;

        // ✅ Only add path when it's a leaf and sum matches
        if (!root->left && !root->right && curr == targetSum) {
            path.push_back(currentpath);
        }

        if (root->left) {
            dfs(root->left, targetSum, currentpath, path, curr);
        }

        if (root->right) {
            dfs(root->right, targetSum, currentpath, path, curr);
        }

        // ✅ Backtrack
       // currentpath.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> currentpath;
        vector<vector<int>> path;
        dfs(root, targetSum, currentpath, path, 0);
        return path;
    }
};
