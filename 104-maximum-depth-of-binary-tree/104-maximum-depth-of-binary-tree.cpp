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
#define MAX(a,b) (a>b?a:b);
class Solution {
public:
    int dfs(TreeNode * root)
    {
        if(root == NULL) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        return MAX(left+1, right+1);
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        //int ans=0;
        return(dfs(root));
    }
};