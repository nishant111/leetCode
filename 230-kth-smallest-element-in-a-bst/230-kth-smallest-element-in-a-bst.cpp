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

/* Do a inorder traversal and keep a count
 * Morris Inorder is the most effecient traversal 
 * As it does not tae extra stack space
 * Hence, we will use that */
class Solution {
public:
    TreeNode* dfs(TreeNode *root, int &count,int k)
    {
        if(root == NULL) return NULL;
        TreeNode* left = dfs(root->left, count, k);
        if(left)
            return left;
        count++; 
        if(count == k)
            return root;
        TreeNode* right = dfs(root->right, count, k);
        if(right)
            return right;
        return NULL;
    }
    int kthSmallest(TreeNode* root, int k) {
        int count1 = 0;
        return dfs(root, count1, k) -> val;
        TreeNode * curr = root;
        int ans;
        int count = 0;
        while(curr !=NULL)
        {
            if(curr -> left == NULL)
            {
                count ++;
                cout <<"Processed "<<curr->val <<"\n";
                if(count == k)
                {
                    cout <<"Found result ";
                    // still need to reset synthetic thread , cant return
                    ans= curr->val;
                }
                curr = curr -> right;
            }
            else if(curr -> left!= NULL)
            {
                TreeNode *tmp = curr->left;
                cout <<"tmp is "<<tmp->val<<"\n";
                while(tmp->right!=NULL && tmp->right != curr)
                {
                    tmp = tmp-> right;
                    cout <<"tmp is "<<tmp->val<<"\n";
                }
                if(tmp-> right == NULL)
                {
                    tmp->right = curr;
                    curr= curr->left;
                }
                else if(tmp->right == curr)
                {
                    // Remove the synthetic thread link to inorder successor
                    tmp->right = NULL;
                    // process the curr, as the left subtree is processed
                    count++;
                    cout <<"Processed "<<curr->val <<"\n";
                    if(count == k)
                        ans = curr->val;
                    curr= curr-> right;
                }
            }
            
        }
        return ans;
    }
};