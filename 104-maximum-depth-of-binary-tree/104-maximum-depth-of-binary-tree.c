/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int max(int l, int r)
{
    return(l>r?l:r);
}

int maxDepth(struct TreeNode* root){
    if (root == NULL)
        return 0;
    int ld;
    int rd;
    int height;
    ld = maxDepth(root->left);
    rd = maxDepth(root->right);
    height=max(ld, rd)+1;
    return height;
}