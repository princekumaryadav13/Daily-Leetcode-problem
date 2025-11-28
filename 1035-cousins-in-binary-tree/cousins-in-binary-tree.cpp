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
   bool parent(TreeNode* root, int x, int y){
    if(!root) return false;
    if(root->left && root->right){
    if(root->left->val == x && root->right->val == y){
        return true;
    }
     if(root->left->val == y && root->right->val == x){
        return true;
     }
    }
    return parent(root->left , x,y) || parent(root->right,x,y);
   }
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*>que;
        que.push(root);
        int l1=-1,l2=-1;
        int level=0;
        while(!que.empty()){
            int n = que.size();
            while(n--){
                TreeNode *temp= que.front();
                que.pop();
                if(temp->val == x){
                    l1= level;
                } 
                if(temp->val == y){
                    l2=level;
                }
                if(temp->left) que.push(temp->left);
                if(temp->right) que.push(temp->right);
            }
            level++;
            if(l1 != l2) return false;
        }
        return !parent( root,  x, y);
    }
};