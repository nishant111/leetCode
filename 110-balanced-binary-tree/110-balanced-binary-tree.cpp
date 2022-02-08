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
    int dfs(TreeNode *root, bool &ans)
    {
        if (root == NULL) return 0;
        int left = dfs(root->left, ans);
        if(left == -1) 
            return -1;
        int right = dfs(root->right, ans);
        if(right==-1) 
            return -1;
        if(left-right>1 || left-right<-1)
            return -1;
        return MAX(left+1, right+1);
        
        
    }
    bool isBalanced(TreeNode* root) {
        bool ans=true;
        if(root == NULL) return true;
        int tmp = dfs(root, ans);
        if (tmp>0)
            return true;
        else
            return false;
    }
};