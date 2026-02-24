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
    vector<vector<int>> ans;
    void dfs(TreeNode* root, vector<int> res) {

        if (root == NULL) return;

        // add current node
        res.push_back(root->val);

        // if leaf node → store path
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(res);
        }

        dfs(root->left, res);
        dfs(root->right, res);
    }
    int binary(vector<vector<int>> ans) {
        int aa =0;
        for (int i = 0; i < ans.size(); i++) {
            int decimalValue = 0;
            int base = 1; // Represents the current power of 2 (2^0, 2^1, ...)

            for (int j = ans[i].size() - 1; j >= 0; j--) {
                if (ans[i][j] == 1) {
                    decimalValue += base;
                }
                base *= 2; // Move to the next power of 2
            }
            aa += decimalValue;
        }
        return aa;
    }
    int sumRootToLeaf(TreeNode* root) {
        vector<int> res;
        dfs(root, res);
        
        return binary(ans);
    }
};