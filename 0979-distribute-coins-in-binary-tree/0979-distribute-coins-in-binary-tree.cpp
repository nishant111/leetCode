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
    int moves = 0;
    int dfs(TreeNode* root) {
        if(root==NULL)
            return 0;   
        int l = dfs(root->left);
        int r = dfs(root->right);
        int currCoins = ( root->val - 1 ) + l + r;
        moves += abs(l) + abs(r);
        return currCoins;
    }
    
    int distributeCoins(TreeNode* root) {
        int currCoins = dfs(root);
        return moves;
    }
};