/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode treeNode;

struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2){
    
    if(root1 == NULL && root2 == NULL)
    {
        return NULL;
    }
    else
    {
        treeNode * root3 = malloc(sizeof(treeNode));
        if(root1!=NULL && root2 != NULL)
        {
            root3->left = mergeTrees(root1->left, root2->left);
            root3->right =  mergeTrees(root1->right, root2->right);
            root3->val = root1->val + root2->val;
        }
        else
        {
            if(root1 == NULL)
            {
                root3 -> val = root2->val;
                root3->left = root2->left;
                root3->right= root2->right;
            }
            else if(root2 == NULL)
            {
                root3 -> val = root1->val;
                root3->left = root1->left;
                root3->right= root1->right;
            }
        }
        return root3;
    }
    
}