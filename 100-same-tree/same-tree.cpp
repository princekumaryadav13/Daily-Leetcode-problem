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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> pp;
        pp.push(p);
        queue<TreeNode*> qq;
        qq.push(q);
        while (!pp.empty() && !qq.empty()) {
            TreeNode* nodep = pp.front();
            pp.pop();
            TreeNode* nodeq = qq.front();
            qq.pop();
            if (!nodep && !nodeq) continue;
            if (!nodep || !nodeq) return false;
            if (nodep->val != nodeq->val) {
                return false;
            }
            pp.push(nodep->left);
            qq.push(nodeq->left);

            pp.push(nodep->right);
            qq.push(nodeq->right);
        }
        return true;
    }
};