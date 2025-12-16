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
    bool ans = true;
    void solve(TreeNode* root,int &height){
       if (root == NULL) {
            height = 0;
            return;
        }

      int lh = 0, rh = 0;

        solve(root->left, lh);
        solve(root->right, rh);

        if (abs(lh - rh) > 1)
            ans = false;
     
        height = 1 + max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {
         int height = 0;
        solve(root, height);
        return ans;
    }
};