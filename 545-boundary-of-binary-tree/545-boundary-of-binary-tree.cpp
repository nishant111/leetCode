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
    TreeNode* leftBoundary(TreeNode* root,vector<int> &ans)
    {
        if(root == NULL) return NULL;
        if(root->left || root->right)
            ans.push_back(root->val);
        TreeNode *left = NULL;
        TreeNode *right = NULL;
        left = leftBoundary(root->left, ans);
        if(left == NULL)
        {
            right = leftBoundary(root->right, ans);
        }
        if(left){
            return left;
        }
        else if(right)
            return right;
        else 
            return root;
    }
    void bottomBoundary(TreeNode* root,vector<int> &ans){
        if(root == NULL) return ;
        if(!root->left && !root->right)
        {
            ans.push_back(root->val);
        }
        bottomBoundary(root->left, ans);
        bottomBoundary(root->right, ans);
        return;
    }
    TreeNode* rightBoundary(TreeNode* root,vector<int> &ans){
        if(root == NULL) return NULL;
        TreeNode *left = NULL;
        TreeNode *right = NULL;
        right = rightBoundary(root->right, ans);
        if(right == NULL)
        {
            left = rightBoundary(root->left, ans);
        }
        if(root->left || root->right) ans.push_back(root->val);
        if(left) return left;
        else if(right) return right;
        else
            return root;
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        ans.push_back(root->val);
        if(root->left)
            leftBoundary( root->left,ans);
        bottomBoundary(root->left,ans);
        bottomBoundary(root->right,ans);
        if(root->right)
            rightBoundary(root->right, ans);
        
        return ans;
    }
};