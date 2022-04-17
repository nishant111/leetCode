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
    TreeNode*prev=NULL;
    void dfs(TreeNode * root)
    {
        if (root == NULL)
        {
            return;
        }
        
        dfs(root->right);
        root->right = prev;
        prev = root;
        dfs(root->left);
        root->left =NULL;
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *realroot = root;
        while(realroot->left !=NULL)
        {
            realroot = realroot->left;
        }
        dfs(root);
        return realroot;
    }
};