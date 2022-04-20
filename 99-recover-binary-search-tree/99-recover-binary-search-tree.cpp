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
    TreeNode *fi = NULL;
    TreeNode *prev = NULL;
    TreeNode * sec = NULL;
    TreeNode * last = NULL;
    void dfs(TreeNode * root)
    {
        if(root == NULL) return;
        
        dfs(root->left);

        if(prev!=NULL && root->val < prev->val)
        {
            if((fi)==NULL)
            {
                fi = prev;
                sec = root;
            }
            else
            {
                last = root;
            }
        }
        prev = root;
        dfs(root->right);
    }
    
    void swap(TreeNode* root1, TreeNode* root2)
    {
        int tmp = root1->val;
        root1->val = root2->val;
        root2->val = tmp;
    }
    
    void recoverTree(TreeNode* root) {
        vector<TreeNode *> inorder;
        
        dfs(root);
        if(last !=NULL)
        {
            swap(fi, last);
        }
        else
            swap(fi, sec);
        
    }
};