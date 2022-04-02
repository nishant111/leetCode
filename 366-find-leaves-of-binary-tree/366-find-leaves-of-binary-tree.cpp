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
    TreeNode* dfs(TreeNode *root, vector<int> &leaves)
    {
        if(root == NULL) return NULL;
        if(root->left==NULL && root->right==NULL){
            leaves.push_back(root->val);
            return NULL;
        }
        root->left = dfs(root->left, leaves);
        root->right = dfs(root->right, leaves);
        return root;
    }
    vector<vector<int>> findLeaves1(TreeNode* root) {
        vector<int> leaves;
        vector<vector<int>> ans;
        while(root)
        {
            leaves.clear();
            root = dfs(root, leaves);
            ans.push_back(leaves);
        }
        return ans;
    }
    
    int findAnsUsingHeights(TreeNode *root, vector<vector<int>> &ans)
    {
        if(root == NULL) return -1;
        int lh = findAnsUsingHeights(root->left, ans);
        int rh = findAnsUsingHeights(root->right, ans);
        int currh = max(lh,rh) + 1;
        if (currh >= ans.size())
        {
            ans.push_back({});
        }
        ans[currh].push_back(root->val);
        return currh;
    }
    
     vector<vector<int>> findLeaves(TreeNode* root) {
         vector<vector<int>> ans;
         if(root == NULL) return ans;
         findAnsUsingHeights(root, ans);
         return ans;
     }
};