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
    void fll(TreeNode *root, vector<TreeNode*> &preorder)
    {
        if(root == NULL) return;
        preorder.push_back(root);
        fll(root->left, preorder);
        fll(root->right, preorder);
    }
    void flatten(TreeNode* root) {
        vector <TreeNode *>preorder;
        fll(root,preorder);
        int it = 0;
        while (it<preorder.size())
        {
            if(it == preorder.size()-1)
            {
                preorder[it]->right = NULL;
                break;
            }
            preorder[it] ->left = NULL;
            preorder[it] ->right = preorder[it+1];
            it++;
        }
    }
};