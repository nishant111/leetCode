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
    int dfs(TreeNode *root, int count, int &ans)
    {
        if(root->right == NULL && root->left != NULL)
        {
            ans = max(count*2, ans);
            return count *2;
        }
        if(!(root->left) && !(root->right) )
        {
            ans = max(count, ans);
            return 0;
        }
        int l,r;
        l = dfs(root->right,(count*2)+1, ans);
        if(l) return l;
        r = dfs(root->left, (count*2), ans);
        if(r) return r;
        return 0;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        int ans=INT_MIN;
        int rval = INT_MIN;
        rval = dfs(root, 1, ans);
        return max(rval, ans);
    }
};