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
    void dfs (TreeNode *root, vector <int> &ans)
    {
        if(root == NULL)
            return;
        dfs(root->left, ans);
        ans.push_back(root->val);
        dfs(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        //dfs(root, ans);
        /* Iterative solution */
        TreeNode *curr = root;
        stack <TreeNode *> st;
        while(curr!=NULL ||st.empty()!= true)
        {
            while(curr)
            {
                st.push(curr);
                curr = curr->left;
            }
            ans.push_back(st.top()->val);
            curr = st.top()->right;
            st.pop();
        }
        return ans;
    }
};