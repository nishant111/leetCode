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
    bool dfs(TreeNode *p, TreeNode *q)
    {
        if(p==NULL && q== NULL) return true;
        if( (p==NULL && q!=NULL)|| (p!=NULL &&q==NULL)) return false;
        if(p->val != q->val) return false;
        bool left = dfs(p->left, q->left);
        if(!left) 
            return false;
        bool right = dfs(p->right, q->right);
        if(!right)
            return false;
        return true;
            
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ans = dfs(p,q);
        return ans;
    }
};