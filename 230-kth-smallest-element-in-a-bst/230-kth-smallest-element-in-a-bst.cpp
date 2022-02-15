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
    int kthSmallest(TreeNode* root, int k) {
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
                    // reset synthetic thread
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