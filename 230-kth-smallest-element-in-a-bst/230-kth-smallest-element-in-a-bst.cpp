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
    int dfs(TreeNode *root, int k, int &count)
    {
        if(root==NULL) return -1;
        int left;int right;
        left = dfs(root->left, k, count);
        if(left>-1) return left;
        count++;
        if(count == k) return root->val;
        right = dfs(root->right, k, count);
        if(right>-1) return right;
        return -1;
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        return dfs(root, k, count);      
    }
};