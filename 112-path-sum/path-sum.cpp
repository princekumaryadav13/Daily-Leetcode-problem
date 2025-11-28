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
    bool check(TreeNode* node, int targetSum, int currsum) {
        if(node == nullptr) 
            return false;

        currsum += node->val;

        if(node->left == nullptr && node->right == nullptr) {
            return currsum == targetSum;
        }

        bool leftAns = check(node->left, targetSum, currsum);
        bool rightAns = check(node->right, targetSum, currsum);

        return leftAns || rightAns;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return check(root, targetSum, 0);
    }
};
