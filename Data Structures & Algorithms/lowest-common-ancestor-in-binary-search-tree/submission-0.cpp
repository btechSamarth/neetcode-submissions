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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q){
            return root;
        }
        TreeNode * left = NULL;
        TreeNode * right = NULL;
        if(p->val < root->val && q->val < root->val){
            left = lowestCommonAncestor(root->left , p , q);
        }
        else if(p->val > root->val && q->val > root->val){
            right = lowestCommonAncestor(root->right , p , q);
        }
        else if((p->val < root->val && q->val > root->val) || (p->val > root->val && q->val < root->val)){
            return root;
        }

        return left == NULL ? right : left;
        
    }
};
