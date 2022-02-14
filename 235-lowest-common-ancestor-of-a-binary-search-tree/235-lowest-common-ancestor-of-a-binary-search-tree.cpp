/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/* Soln using BST Property O(log n)*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *curr = root;
        while(curr !=NULL)
        {
            if( (p->val <= curr->val && q->val >= curr->val)  ||
                (p->val >= curr->val && q->val <= curr->val ))
            {
                // split happening here, hence this is LCA
                return curr;
            }
            else if(p->val > curr->val && q->val > curr->val)
            {
                curr = curr-> right; 
            }
            else
            {
                curr = curr->left;
            }
        }
        return NULL;
    }
};


/*
DFS Solution (O(n))
class Solution {
public:
    TreeNode * dfs(TreeNode * root, TreeNode *p, TreeNode *q)
    {
        if(root == NULL) return NULL;
        if(root == p || root == q) return root;
        TreeNode *left = dfs(root->left, p, q);
        TreeNode *right = dfs(root->right, p, q);
        if(left && right) return root;
        if(left) return left;
        if(right) return right;
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      return (dfs(root, p, q));  
    }
};*/