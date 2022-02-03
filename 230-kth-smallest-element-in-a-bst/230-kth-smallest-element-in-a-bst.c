/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

uint ans = 0;

void inorder(struct TreeNode* root,int k,int* idx)
{
    if(root==NULL) return;
    inorder(root->left,k,idx);
    //printf("\nk is %d & count is %d",k,count);
    (*idx)++;
    if(*idx == k)
    {
        ans = root->val;
        return;
    }
    inorder(root->right,k,idx);
}


int kthSmallest(struct TreeNode* root, int k){
    if(root==NULL) return 0;
    int res;
    int idx=0;
    inorder(root,k,&idx);
    idx = 0; // reset idx for next call
    return ans;
}