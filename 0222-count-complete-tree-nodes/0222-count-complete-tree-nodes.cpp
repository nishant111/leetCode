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
    /* count is always holding the current count, ans holds the overall count, try dry run for clarity,
    Another approach would be to:
    1.find left h and right h if ther are equal there are 
    (2^left h) -1 nodes,
    2.otherwise do dfs on left then right*/
    int dfs(TreeNode * root, int count, int &ans)
    {
        if(root -> left != NULL && root -> right == NULL)
        {
            return count*2;
        }
        if(root -> left == NULL && root -> right == NULL)
        {
            ans = max(count,ans);
            return 0;
        }
        
        int r, l;
        r = dfs(root->right, (count*2)+1, ans);
        if(r) return r;
        l = dfs(root->left, (count*2),ans);
        if(l) return l;
        return 0;
    }
    
    
    
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int ans = INT_MIN;
        int ret= dfs(root, 1, ans);
        return(max(ret,ans));
    }
};