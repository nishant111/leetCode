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
    string dfs(unordered_map<string ,int> &pre, vector<TreeNode*> &ans, TreeNode* root) {
        if(root == NULL)
        {
            return "#";
        }

        string c = to_string(root->val);
        string l = dfs(pre, ans, root->left);
        string r = dfs(pre, ans, root->right);
        string result = c + ',' +l + ','+r;
        if(pre.find(result)!=pre.end())
        {
            if(pre[result] == 1)
            {
                // capture it in ans only for once, ignore afterwards
                ans.push_back(root);
            }
        }
        pre[result]++;
        return result;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> pre;
        vector<TreeNode*> ans;
        dfs(pre, ans, root);
        return ans;
    }
};