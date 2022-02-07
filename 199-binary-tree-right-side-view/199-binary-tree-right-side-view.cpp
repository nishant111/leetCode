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
    /*Iterative Soln */
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        TreeNode * curr = root;
        queue <TreeNode *> q;
        q.push(root);
        ans.push_back(q.back()->val);
        while(q.empty()!=true)
        {
            int size = q.size();
            int pushCount = 0;
            for(int j = 0;j<size;j++)
            {
                //TreeNode *tmp;
                curr = q.front();
                q.pop();
                if(curr->left)
                {
                    q.push(curr -> left);
                    pushCount++;
                }
                if(curr->right)
                {
                    q.push(curr ->right);
                    pushCount++;
                }
            }
            if(pushCount>0)
                ans.push_back(q.back()->val);
        }
        return ans;
    }
};




/*
class Solution {
public:
    //doing  recurssion
    void dfs(TreeNode *root , vector<int> &ans, int level)
    {
        if(root == NULL)
            return;
        if(ans.size() == level)
            ans.push_back(root->val);
        dfs(root->right, ans, level+1);
        dfs(root->left, ans, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        //ans.push_back(root->val);
        dfs(root ,ans, 0);
         return ans;
    }
   
};
*/