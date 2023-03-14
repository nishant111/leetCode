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
    void dfs(TreeNode *root, long long pval, int& sum) {
        if(root == NULL)
            return;
        if(!root->left && !root->right)
        {
            //leaf node
            sum += (pval + root->val);
        }
        dfs(root -> left , (pval + root->val)*1LL * 10, sum);
        dfs(root -> right, (pval + root->val)*1LL * 10, sum);
        

    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        dfs(root, 0, sum);
        return sum;
    }
};