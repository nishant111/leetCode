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
    TreeNode* dfs(TreeNode* root, int val, int depth, int currDepth){
        if(root == NULL)
            return NULL;
        if(currDepth == depth - 1){
            TreeNode * l = root -> left;
            TreeNode * r = root -> right;
            TreeNode * newNodel = new TreeNode(val, l, NULL);
            TreeNode * newNoder = new TreeNode(val, NULL, r);
            root->left = newNodel;
            root->right = newNoder;
            return root;
        }
        dfs(root->left, val, depth, currDepth + 1);
        dfs(root->right, val, depth, currDepth + 1);
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1){
            TreeNode * newNodeRoot = new TreeNode(val, root, NULL);
            return newNodeRoot;
        }
        return dfs(root, val, depth, 1);   
    }
};