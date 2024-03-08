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
    bool dfs(TreeNode *p, TreeNode *q){
        if(p==NULL && q==NULL) return true;
        if(p && !q) return false;
        if(q && !p) return false;
        if(p->val != q->val) return false;
        bool lr = dfs(p->left, q->right);
        if(!lr) return false;
        bool rl = dfs(p->right, q->left);
        if(!rl) return false;
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        return dfs(root->left, root->right);
    }
};