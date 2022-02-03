/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode TreeNode;

bool isSubtreeLesser(TreeNode* root, int val)
{
    if(root == NULL) return true;
    if(root->val < val &&
       isSubtreeLesser(root->left, val)&&
       isSubtreeLesser(root->right, val))
        return true;
    else
        return false;
    
}

bool isSubtreeGreater(TreeNode* root, int val)
{
    if(root == NULL) return true;
    if(root->val > val &&
       isSubtreeGreater(root->left, val)&&
       isSubtreeGreater(root->right, val))
        return true;
    else
        return false;
}

bool isValidBST(struct TreeNode* root){
    if (root == NULL)
        return true;
    if(isSubtreeLesser(root->left, root->val) &&
       isSubtreeGreater(root->right, root->val) &&
       isValidBST(root->left) &&
       isValidBST(root->right))
        return true;
    else
        return false;
}



/* Efficient solution - Need to revisit failing for MAX and MIN values. */
/*
bool wrapIsValidBST(TreeNode *root, int min, int max)
{
    if(root == NULL) return true;
    if((root->val == INT_MAX || root->val == INT_MIN) && root->left == NULL && root->right == NULL) return true;
    if(root->val == INT_MAX && root->right != NULL) return false;
    if(root->val == INT_MIN && root->left != NULL) return false; 
    if(root->val>min && root->val<max && 
       wrapIsValidBST(root->left, min, root->val) &&
       wrapIsValidBST(root->right, root->val ,max))
        return true;
    else
        return false;
}

bool isValidBST(struct TreeNode* root){
    return wrapIsValidBST(root, INT_MIN, INT_MAX);
}*/
