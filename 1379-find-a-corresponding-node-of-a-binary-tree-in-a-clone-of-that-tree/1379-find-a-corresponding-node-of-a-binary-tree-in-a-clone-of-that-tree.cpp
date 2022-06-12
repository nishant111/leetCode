/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode* dfs(TreeNode* orig, TreeNode* clone, TreeNode* targ)
    {
        if(orig == targ)
        {
            return clone;
        }
        if(orig == NULL || clone == NULL) return NULL;
        
        TreeNode* left =  dfs(orig->left, clone->left, targ);
        if(left)
        {
            return left;
        }
        TreeNode *right = dfs(orig->right, clone->right, targ);
        if(right)
        {
            return right;
        }
        return NULL;
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return dfs(original, cloned, target);
    }
};