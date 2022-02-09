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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>  ans;
        queue <TreeNode*> q;
        if(root == NULL) return ans;
        q.push(root);
        //ans.push_back({root->val});
        bool rl = false;
        while(q.empty()!=true)
        {
            int size = q.size();
            
            int index;
            vector<int> tmp(size);
            if(rl == true)
            {
                index = 0;
            }
            else{
                index = size-1;
            }
            for(int i  = 0;i<size;i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                tmp[index] = curr->val;
                if(curr -> right)
                {
                    q.push(curr->right);
                    
                }
                if(curr->left)
                {
                    q.push(curr->left);
                }
                if(!rl) index--;
                else index++;
                
            }
            ans.push_back(tmp);
            
            rl =!rl;
            
        }
        return ans;
    }
};