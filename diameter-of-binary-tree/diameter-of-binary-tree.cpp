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
    int maxi = INT_MIN;
    int dfs(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int l = dfs(root->left);
        int r = dfs(root->right);
        maxi = max(maxi, l+r );
        return max(l+1, r+1);
    }
     int diameterOfBinaryTree(TreeNode* root) {
        return max(maxi, dfs(root)-1);    
     }
};