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
    void preOrder(TreeNode *root, vector <int> &ans)
    {
        if(root == NULL)
            return;
        ans.push_back(root->val);
        preOrder(root->left, ans);
        preOrder(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        //preOrder(root, ans);
        /* Morris O(N) time and O(1) space , credits : striver */
        
        TreeNode *curr = root;
        while(curr !=NULL)
        {
            if(curr -> left == NULL)
            {
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else if(curr -> left !=NULL)
            {
                //ans.push_back(curr->val);
                TreeNode *tmp = curr->left;
                while(tmp->right!=NULL && tmp->right !=curr)
                {
                    tmp = tmp->right;
                }
                if(tmp->right == NULL)
                {
                    //set thread;
                    tmp->right = curr;
                    ans.push_back(curr->val);
                    // move curr
                    curr = curr->left;
                }
                else if(tmp->right == curr)
                {
                    tmp->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return ans;
        
        /* Iterative soln 
        TreeNode *curr = root;
        stack <TreeNode *> st;
        while(curr || st.empty()!=true)
        {
            while(curr!=NULL)
            {
                ans.push_back(curr->val);
                st.push(curr);
                curr = curr->left;
            }
            //ans.push_back(st.top()->val);
            curr = st.top()->right;
            st.pop();
        }
        return ans;*/
    }
};