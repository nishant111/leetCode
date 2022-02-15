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
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(TreeNode *root, vector<int> &inorder)
    {
        if(root== NULL) return;
        dfs(root->left, inorder);
        inorder.push_back(root->val);
        dfs(root->right, inorder);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        dfs(root, inorder);
        int left = 0;
        int right = inorder.size()-1;
        while(left<right)
        {
            if(inorder[left] + inorder[right]<k)
            {
                left++;
            }
            else if(inorder[left] + inorder[right]>k)
            {
                right--;
            }
            else
                return true;
        }
        return false;
    }
};