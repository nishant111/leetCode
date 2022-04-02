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
    
    TreeNode* dfs(TreeNode *root, vector<TreeNode*> &ans, unordered_set<int> &st)
    {
        if(root == NULL) return NULL;
        root->left = dfs(root->left, ans, st);
        root->right = dfs(root->right, ans, st);
        
        if(st.find(root->val)!=st.end())
        {
            if(root->left)
                ans.push_back(root->left);
            if(root->right)
                ans.push_back(root->right);
            return NULL;
        }
        return root;
            
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_set <int> st;
        
        for(int i = 0;i<to_delete.size();i++)
        {
            st.insert(to_delete[i]);
        }
        if(st.find(root->val)==st.end())
        {
            ans.push_back(root);
        }
        dfs(root, ans, st);
        return ans;
    }
};