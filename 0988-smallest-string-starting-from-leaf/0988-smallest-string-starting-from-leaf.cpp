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
    string ans = "";
    void dfs(TreeNode *root, string curr){
        if(!root)
            return;
        curr = char(root->val+'a') + curr;
        if(!root->left && !root->right){
            if(ans.size()==0 || curr<ans){
                ans = curr;
            }
        }
        dfs(root->left, curr);
        dfs(root->right, curr);
    }
    string smallestFromLeaf(TreeNode* root) {
        if(!root) return "";
        dfs(root, "");
        return ans;
    }
};