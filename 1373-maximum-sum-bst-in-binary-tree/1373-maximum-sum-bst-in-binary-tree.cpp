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

class rval{
    public:
        int sum;
        bool isBst;
        int min;
        int max;
};

class Solution {
public:
    rval dfs(TreeNode* root, int &ans)
    {
        if(root == NULL)
        {
            rval r = {0, true, INT_MAX, INT_MIN}; // comparison always passes
            return r;
        }
        rval left = dfs(root->left, ans);
        rval right = dfs(root->right, ans);
        rval r;
        if(root->val > left.max && root->val < right.min)
        {
            //valid bst
            r = {(left.sum + right.sum + root->val), true ,
                      min(root->val, left.min), max(root->val, right.max)};
            
        }
        else
        {
            //invalid bst, return invalid values here so that all parent 
            // comparisons fails
            r = { max(left.sum, right.sum),false, INT_MIN, INT_MAX};
        }
        ans = max(ans, r.sum);
        return r;
        
    }
    int maxSumBST(TreeNode* root) {
        int ans= INT_MIN;
        rval r = dfs(root, ans);
        return ans>0?ans:0;
    }
};