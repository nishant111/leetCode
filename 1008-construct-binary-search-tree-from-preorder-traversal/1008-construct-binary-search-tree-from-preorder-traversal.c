/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode TreeNode; 

int findFirstGreater(int *preorder, int start, int end)
{
    for(int i = start;i<=end;i++)
    {
        if(preorder[i]>preorder[start])
            return i-1;
    }
    return end;
}

TreeNode* dfs(int* preorder, int start, int end){
    if(start>end || start<0 ) return NULL;
    // first element in preorder is always the root
    TreeNode *root = (TreeNode*)calloc(1, sizeof(TreeNode));
    root->val = preorder[start];
    printf("Inserted Element %d \n",root->val);
    //find first elem greater than root
    int idx = findFirstGreater(preorder, start, end);
    root->left = dfs(preorder, start+1, idx );
    root->right = dfs(preorder, idx+1, end);
    return root;
}

struct TreeNode* bstFromPreorder(int* preorder, int preorderSize){
    if(preorderSize == 0) return NULL;
    return dfs(preorder, 0, preorderSize-1);
    
}