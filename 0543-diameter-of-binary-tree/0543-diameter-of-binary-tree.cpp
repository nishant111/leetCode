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
    pair<int,int> dfs(TreeNode *root){
        if (root == NULL){
            return {0,0};
        }
        int left; int right; left=right= 0;
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        if(root->left)
            left = 1 + l.second;
        if(root->right)
            right = 1 + r.second;
        
        return {max((left + right), max(l.first,r.first)),max(left,right)}; 
        
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        auto a =  dfs(root);
        return max(a.first, a.second);
    }
};