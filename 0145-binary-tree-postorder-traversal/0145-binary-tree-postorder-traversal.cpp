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
    
    vector<int> postorderTraversal(TreeNode* root) {
        if(root== NULL) return {};
        vector<int> ans;
        vector<int> l  = postorderTraversal(root->left);
        vector<int> r = postorderTraversal(root->right);
        for(auto el:l){
            ans.push_back(el);
        }
        for(auto el:r){
            ans.push_back(el);
        }
        ans.push_back( root->val);
        return ans;
    }
};