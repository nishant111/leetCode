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
    bool dfs(TreeNode *root, long l, long r)
    {
        if(root == NULL) return true;
        
        if(root ->val <= l || root->val >= r) return false; //Out of Bounds
        //Check recursively
        return(dfs(root->left, l, root->val) &&
               dfs(root->right, root->val, r));
    }
    bool isValidBST(TreeNode* root) {
        return (dfs(root, LONG_MIN, LONG_MAX));
    }
};




/*
Too much traversal on each step
class Solution {
public:
    // sub means subtree
    bool isSubtreeLesser(TreeNode *sub, int targ)
    {
        if(sub == NULL) return true;
        if (sub->val >= targ ) return false;
        return (isSubtreeLesser(sub->left, targ) &&
                isSubtreeLesser(sub->right, targ) );
        //return true;
    }
    //sub means subtree
    bool isSubtreeGreater(TreeNode *sub, int targ)
    {
        if(sub == NULL) return true;
        if(sub->val <= targ ) return false;
        return ( isSubtreeGreater(sub->left, targ) &&
                 isSubtreeGreater(sub->right, targ) );
          //return true;
    }
    bool dfs(TreeNode *root)
    {
        if(root == NULL) return true;
        return (isSubtreeLesser(root->left, root->val) && 
                isSubtreeGreater(root->right, root->val) &&
                dfs(root->left) &&
                dfs(root->right));
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root);
    }
};
*/