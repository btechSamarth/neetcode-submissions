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
    void solve(TreeNode * root , int& count , int& maxval){
        if(root == NULL){
            return;
        }
        if(maxval <= root->val){
            count++;
        }
        int old = maxval;
        maxval = max(maxval , root->val);
        solve(root->left , count , maxval);
        solve(root->right , count , maxval);
        maxval = old;
        return;
    }
    int goodNodes(TreeNode* root) {
        int count = 0;
        solve(root , count , root->val);
        return count;
    }
};
