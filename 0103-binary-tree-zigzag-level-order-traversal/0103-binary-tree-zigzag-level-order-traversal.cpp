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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};
        bool left2right = true;
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty()!=true)
        {
            int size = q.size();
            ans.push_back(vector<int>(size));
            int i;
            if(left2right)
                i = 0;
            else
                i=size-1;
            while(size-->0){
                TreeNode* curr = q.front();
                ans.back()[i] = curr->val;
                q.pop();
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                if(left2right)
                    i++;
                else
                    i--;
            }
            left2right = !left2right;
        }
        return ans;

    }
};