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
    
    void dfs(TreeNode* root, int val, int depth, int currDepth)
    {
        if(root == NULL) return;
        
        if(currDepth == depth-1)
        {
            TreeNode *newLeft = root->left;
            TreeNode *newRight = root->right;
            TreeNode *tmp = new TreeNode(val, newLeft, NULL);
            root->left = tmp;
            tmp = new TreeNode(val, NULL, newRight);
            root -> right = tmp;
            return;
        }
        dfs(root->left, val, depth, currDepth+1);
        dfs(root->right, val, depth, currDepth+1);
        return;
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1)
        {
            // add the node as the root of the tree.
            TreeNode* newRoot = new TreeNode(val, root, NULL);
            return newRoot;
        }
        else
        {
            dfs(root, val, depth, 1);
            return root;
        }
    }
};