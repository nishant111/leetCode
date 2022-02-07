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
    void dfs(TreeNode *root, vector<int> &ans)
    {
        if(root == NULL)
            return;
        dfs(root->left, ans);
        dfs(root->right, ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        //dfs(root, ans);
        /* iterative soln using two stack, can also be done in one stack */
        stack <TreeNode *> st;
        stack <TreeNode *> ch;
        TreeNode *curr = root;
        ch.push(root);
        while(ch.empty()!=true)
        {
            TreeNode *tmp = ch.top();
            st.push(tmp);
            ch.pop();
            if(tmp->left)
                ch.push(tmp->left);
            if(tmp->right)
                ch.push(tmp->right);
        }
        
        while(st.empty()!=true)
        {
            ans.push_back(st.top()->val);
            st.pop();
        }
        
        return ans;
        
        
        
        /*while(curr || st.empty()!=true)
        {
            if(curr)
            {
                st.push(curr);
                curr = curr ->left;
            }
            else
            {
                //curr = st.top();
                //st.pop();
                if(st.top()->right == NULL)
                {
                    ans.push_back();
                    node *tmp = st.top();
                    st.pop;
                    curr = st.top();
                    if(curr->right == tmp)
                    {
                        
                    }
                }

                else
                {
                    //curr->right exists need to go there and traceback and print root
                    curr = st.top()->right;

                }
                //st.pop();
            }
        }
        return ans;*/
    }
};