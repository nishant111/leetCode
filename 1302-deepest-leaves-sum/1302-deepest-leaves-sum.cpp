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
    void dfs(TreeNode *root, map <int, vector<int>> &m, int currLev)
    {
        if(root == NULL) return;
        m[currLev].push_back(root->val);
        
        dfs(root->left, m, currLev+1);
        dfs(root->right, m, currLev+1);
        
    }
    int deepestLeavesSum(TreeNode* root) {
        map <int, vector<int>> m;
        dfs(root, m, 0);
        
        int sum = 0;
        auto i = m.rbegin();
        vector<int> val = i->second;
        
        
        for(int j = 0;j<val.size();j++)
        {
            sum+= val[j];
        }
        return sum;
    }
};