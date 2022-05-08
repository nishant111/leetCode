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
    int sum = 0;
    void dfs(TreeNode *root, int p, int gp)
    {
        if(root == NULL) return;
        dfs(root->left, root->val, p);
        dfs(root->right, root->val, p);
        if(gp!= 0 && gp %2 == 0)
        {
            sum += root->val;
        }
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        dfs(root, 0, 0);
        return sum;
    }
};