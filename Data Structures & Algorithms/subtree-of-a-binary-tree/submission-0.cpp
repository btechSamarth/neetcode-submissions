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
    bool solve(TreeNode*root , TreeNode * subroot){
        if(root == NULL && subroot == NULL){
            return true;
        }
        if(root==NULL || subroot == NULL){
            return false;
        }
        bool flag1 = root->val == subroot->val;
        bool flag2 = solve(root->left , subroot->left);
        bool flag3 = solve(root->right , subroot->right);

        return (flag1 && flag2 && flag3);
    }

    bool solve2(TreeNode* root , TreeNode* subroot){
        if(root == NULL && subroot == NULL){
            return true;
        }
        if(root==NULL || subroot == NULL){
            return false;
        }
        bool left = false;
        bool right = false;
        bool flag = false;
        if(root->val == subroot->val){
            flag = solve(root->left , subroot->left) && solve(root->right , subroot->right);
        }
        left = solve2(root->left , subroot);
        right = solve2(root->right , subroot);
    
        return flag || left || right;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return solve2(root , subRoot);
    }
};
