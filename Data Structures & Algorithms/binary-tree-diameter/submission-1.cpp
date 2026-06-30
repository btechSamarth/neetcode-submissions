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
    int solve(TreeNode* root , int &ans){
        int lefty =0;
        int righty = 0;
        if(root->left){
            lefty = solve(root->left , ans);
        }
        if(root->right){
            righty = solve(root->right , ans);
        }
        int num = lefty + righty;
        ans = max({ans , lefty , righty , num });
        return max(lefty , righty) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int ans = INT_MIN;
        int num = solve(root , ans);
        return ans;
    }
};
