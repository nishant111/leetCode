/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode TreeNode;

bool traverseBothChild(TreeNode* left, TreeNode* right)
{
    if(!left && !right)
        return true;
    else if(left!=NULL&& right!=NULL)
    {
        //return false;
        if(left->val != right->val)
            return false;
        return traverseBothChild(left->left, right->right) && traverseBothChild(left->right,right->left);
    }
    else
        return false;
}

bool isSymmetric(struct TreeNode* root){
    if (root == NULL) 
        return true;
    return (traverseBothChild(root->left, root->right));

}