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
    void dfs(TreeNode *root, int mini, int maxi, int &diff){
        if(root == NULL){
            return;
        }
        maxi = max(maxi, root->val);
        mini = min(mini, root->val);
        diff = max(diff, abs(root->val-mini));
        diff = max(diff, abs(root->val-maxi));
        dfs(root->left, mini, maxi, diff);
        dfs(root->right, mini, maxi, diff);
        return;
    }
    int maxAncestorDiff(TreeNode* root) {
        int diff = 0;
        dfs(root, INT_MAX, INT_MIN, diff);
        return diff;
    }
};