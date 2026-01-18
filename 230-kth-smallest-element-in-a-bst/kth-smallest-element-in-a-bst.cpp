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
    priority_queue<int, vector<int>, greater<int>> que;
    void check(TreeNode* root) {
        
        que.push(root->val);
        if (root->left)
            check(root ->left);
        if (root->right)
            check(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {

        check(root);
        int ans;
        while (k) {
            if (k == 1) {
                ans = que.top();
            }
            que.pop();
            k--;
        }

        return ans;
    }
};