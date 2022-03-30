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
    int dfs1(TreeNode *root, int count, int &ans)
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
        l = dfs1(root->right,(count*2)+1, ans);
        if(l) return l;
        r = dfs1(root->left, (count*2), ans);
        if(r) return r;
        return 0;
    }
    int heightl(TreeNode *root)
    {
        int h = 0;
        while(root)
        {
            h++;
            root = root->left;
        }
        return h;
    }
    
    int heightr(TreeNode *root)
    {
        int h = 0;
        while(root)
        {
            h++;
            root = root->right;
        }
        return h;
    }
    
    int dfs(TreeNode *root)
    {
        if(root == NULL ) return 0;
        if(!root->left && !root->right) return 1;
        //find left deepest count includes root
        int lh = heightl(root);
        //find right deepest count includes root;
        int rh = heightr(root);
        
        if(lh == rh){
            //tree completely filled, no gap inbetween
            return ((1<<lh)-1);
        }
        else
        {
            return 1+(dfs(root->left)) + dfs(root->right) ;
        }
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        return dfs(root);
    }
    int countNodes1(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        int ans=INT_MIN;
        int rval = INT_MIN;
        rval = dfs1(root, 1, ans);
        return max(rval, ans);
    }
};