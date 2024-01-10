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
    void dfs(TreeNode *root, unordered_map<TreeNode *, TreeNode *>& parent,  TreeNode **s, int start){
        if(root==NULL)
            return;
        if(root->val==start){
            (*s)=root;
        }
        if(root->left)
            parent[root->left] = root;
        if(root->right)
            parent[root->right] = root;
        dfs(root->left, parent, s, start);
        dfs(root->right, parent, s, start);
    }
    int time(TreeNode *root, unordered_map<TreeNode *, TreeNode *>& parent, unordered_set <TreeNode *>& vis){
        if(root==NULL)
            return 0;
        vis.insert(root);
        int ans = 0;
        bool t = false;
        if(parent[root]!=NULL && vis.find(parent[root])==vis.end()){
            ans=max(ans,time(parent[root], parent, vis));
            t=true;
        }
        if(root->left && vis.find(root->left)==vis.end()){
            ans=max(ans,time(root->left, parent, vis));
            t=true;
        }
        if(root->right && vis.find(root->right)==vis.end()){
            ans=max(ans,time(root->right, parent, vis));
            t=true;
        }
        if(!t){
            return 0;
        }
        return ans+1;
    }
    
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode *, TreeNode *> parent;
        TreeNode *s =NULL;
        dfs(root, parent, &s, start);
        unordered_set <TreeNode *> vis;
        return time(s, parent, vis);
    }
};