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
    TreeNode* dfs(vector<int> &preorder, int &iter, int rbound)
    {
        if(iter == preorder.size() || preorder[iter]>rbound  ) return NULL;
        TreeNode *root = (TreeNode*)calloc(1, sizeof(TreeNode));
        root->val = preorder[iter++];
        root->left = dfs(preorder, iter, root->val);
        root->right = dfs(preorder, iter, rbound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int iter=0;
        return(dfs(preorder, iter, INT_MAX) );
    }
};