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
    void dfs(TreeNode* rt, int targetSum,int &count,long currsum){
        if(!rt) return ;

        currsum +=rt->val;
        if(currsum == targetSum){
            count++;
        }
        if(rt->left){
            dfs(rt->left,targetSum,count,currsum);
        }
        if(rt->right){
            dfs(rt->right,targetSum,count,currsum);
        }
    }
    void traverse(TreeNode* root , int targetSum , int &count ){
        if(!root) return;

        dfs(root,targetSum,count,0);

        traverse(root->left,targetSum,count);
        traverse(root->right,targetSum,count);
    }
    int pathSum(TreeNode* root, int targetSum) {
        int count=0;
       traverse(root, targetSum, count);
        return count;
    }
};