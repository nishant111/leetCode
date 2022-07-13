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
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        vector<int> tmp;
        q.push(root);
        while(q.empty()!=true)
        {
            int size = q.size();
            while(size-->0)
            {
                TreeNode *curr = q.front();
                q.pop();
                tmp.push_back(curr->val);
                if(curr->left)
                {
                    q.push(curr->left);
                    
                }
                if(curr->right)
                {
                    q.push(curr->right);
                }
                
            }
            ans.push_back(tmp);
            tmp.clear();
        }
        return ans;
    }
    vector<vector<int>> levelOrder1(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        vector<int> tmp;
        tmp.push_back(root->val);
        q.push(root);
        while(q.empty()!=true)
        {
            ans.push_back(tmp);
            tmp.clear();
            int size = q.size();
            for(int i = 0;i<size;i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                if(curr->left)
                {
                    q.push(curr->left);
                    tmp.push_back(curr->left->val);
                }
                if(curr->right)
                {
                    q.push(curr->right);
                    tmp.push_back(curr->right->val);
                }
                
            }
        }
        return ans;
    }
};