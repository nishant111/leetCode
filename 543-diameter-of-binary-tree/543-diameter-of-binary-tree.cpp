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
#define MAX(a,b) a>b?a:b;
class Solution {
public:
    int dfs(TreeNode* root, int &d)
    {
        if(root == NULL) return 0;
        int left = dfs(root->left, d);
        int right = dfs(root->right, d);
        if(left+right>d) 
            d = left+right;
        return MAX(left+1,right+1);
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        int tmp =dfs(root,d);
        return d;
    }
};