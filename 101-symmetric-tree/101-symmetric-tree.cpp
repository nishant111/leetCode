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
    bool dfs(TreeNode *root1, TreeNode *root2)
    {
        if(root1 == NULL || root2 == NULL) return root1==root2;
        if(root1->val!=root2->val) return false;
        TreeNode *root1l = root1->left;
        TreeNode *root2r =root2->right;
        TreeNode *root1r = root1->right;
        TreeNode *root2l = root2->left;
        return (dfs(root1l, root2r) & dfs(root1r, root2l) );
    }
    bool isSymmetric(TreeNode* root) {
       return (dfs(root->left, root->right));
    }
};