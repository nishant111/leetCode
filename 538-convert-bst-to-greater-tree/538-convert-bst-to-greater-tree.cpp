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
    void dfs(TreeNode *root, int &sumToBeAdded)
    {
        if(root== NULL)
            return;
        
        dfs(root->right, sumToBeAdded);
        root->val += sumToBeAdded;
        sumToBeAdded = root->val;
        dfs(root->left, sumToBeAdded);
        
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        dfs(root,sum);
        return root;
    }
};