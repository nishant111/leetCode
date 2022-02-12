/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

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
typedef struct TreeNode TreeNode;
    int find(int *arr, int targ, int size)
    {
        for(int i = 0;i<size;i++)
        {
            if(arr[i] == targ)
                return i;
        }
        return -1;
    }
    
    TreeNode * dfs(int *inorder, int inStart, int inEnd, int *postorder, int postStart, int postEnd , int numsLeft, int numsRight, int inorderSize)
    {
        //if(numsLeft == 0 || numsRight == 0) return NULL;
        if(postStart>postEnd || inStart > inEnd) return NULL;
        TreeNode * curr = (TreeNode *)calloc(1, sizeof(TreeNode));
        curr -> val = postorder[postEnd]; // last elem will be curr
        int idx = find(inorder, curr->val, inorderSize);
        numsLeft = (idx) - (inStart);
        numsRight = inEnd - (idx+1) + 1;
        //postorder.pop_back();
        curr -> left = dfs(inorder, inStart, idx-1,
                           postorder,postStart ,postStart  + numsLeft-1,
                           numsLeft, numsRight, inorderSize);
        
        curr -> right =  dfs(inorder, idx+1, inEnd,
                           postorder, postStart  + numsLeft  , postEnd-1,
                           numsLeft, numsRight, inorderSize);
        //postorder.pop_back();
        /*if(curr->left && curr->right)
        cout<< curr->val <<" left child is "<<curr->left->val <<" & right child is "<<curr->right->val<<"\n";
        else
            cout<< curr->val <<" left child is NULL "<<" & right child is NULL"<<"\n";*/
        return curr;
    }
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    return ( dfs(inorder, 0, inorderSize-1, postorder, 0, postorderSize-1, -1, -1, inorderSize) );
}