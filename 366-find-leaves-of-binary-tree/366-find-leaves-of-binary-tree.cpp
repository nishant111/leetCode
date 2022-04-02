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
    TreeNode* dfs(TreeNode *root, vector<int> &leaves)
    {
        if(root == NULL) return NULL;
        if(root->left==NULL && root->right==NULL){
            leaves.push_back(root->val);
            return NULL;
        }
        root->left = dfs(root->left, leaves);
        root->right = dfs(root->right, leaves);
        return root;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<int> leaves;
        vector<vector<int>> ans;
        while(root)
        {
            leaves.clear();
            root = dfs(root, leaves);
            ans.push_back(leaves);
        }
        return ans;
    }
};