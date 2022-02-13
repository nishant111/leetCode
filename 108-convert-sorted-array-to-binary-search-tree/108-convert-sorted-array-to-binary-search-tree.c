/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode TreeNode ;
TreeNode* dfs(int *nums, int size ,int start, int end)
    {
        if(start>end) return NULL;
        int mid = (start+end)/2;
        TreeNode *root = calloc(1, sizeof(TreeNode));
        root->val = nums[mid];
        root->left = dfs(nums, size, start, mid-1);
        root->right = dfs(nums, size, mid+1, end);
        return root;
        
    }
struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    return (dfs(nums, numsSize , 0, numsSize-1));
}