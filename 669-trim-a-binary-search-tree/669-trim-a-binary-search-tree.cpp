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
    TreeNode * dfs(TreeNode * root, int low, int high)
    {
        if(root == NULL) return root;
        
        root -> left = dfs(root->left, low, high);
        root -> right = dfs(root->right, low , high);
        if(root->val < low || root->val > high)
        {
            //not in bound
            if(root->left) 
                return root->left;
            else if(root->right) 
                return root->right;
            else 
                return NULL;
            
        }
        return root;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return dfs(root, low, high);
    }
};