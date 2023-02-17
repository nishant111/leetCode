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
    int ans = INT_MAX;
    TreeNode * prev = NULL;
    void dfs(TreeNode *root){
        if(root == NULL)
            return;
        dfs(root -> left);
        if(prev)
            ans = min(ans, abs(prev->val - root->val));
        prev = root;
        dfs(root->right);
        
    }
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};