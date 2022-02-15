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

/* 1. can be done using BST Iterator concept (Leetcode 173) 
   2. can be done using inorder(morris is effecient) traversal then two pointer approach for inorder array*/
class Solution {
public:
    stack<TreeNode*> stLeft; // ascending stack
    stack<TreeNode *> stRight; // descending stack
    void iteratorLeft(TreeNode *root)
    {
        //creates ascending stack
        TreeNode *curr = root;
        while(curr!=NULL)
        {
            stLeft.push(curr);
            curr = curr->left;
        }
    }
    void iteratorRight(TreeNode *root)
    {
        //creates descending stack
        TreeNode* curr = root;
        while(curr!=NULL)
        {
            stRight.push(curr);
            curr = curr->right;
        }
    }
    int nextAscending()
    {
        TreeNode *curr = stLeft.top();
        int rtval = curr->val;
        if(curr->right == NULL)
        {
            stLeft.pop();
        }
        else if(curr->right !=NULL)
        {
            stLeft.pop();
            curr = curr -> right;
            while(curr!=NULL)
            {
                stLeft.push(curr);
                curr = curr->left;
            }
            
        }
        return rtval;
    }
    int nextDescending()
    {
        TreeNode * curr = stRight.top();
        int rtval = curr->val;
        if(curr ->left == NULL)
        {
            stRight.pop();
        }
        else if(curr->left!=NULL)
        {
            stRight.pop();
            curr = curr->left;
            while(curr!=NULL)
            {
                stRight.push(curr);
                curr = curr->right;
            }
        }
        return rtval;
    } 
    void dfs(TreeNode *root, vector<int> &inorder)
    {
        if(root== NULL) return;
        dfs(root->left, inorder);
        inorder.push_back(root->val);
        dfs(root->right, inorder);
    }
    bool findTarget(TreeNode* root, int k) {
        
        iteratorLeft(root);
        iteratorRight(root);
        int left = nextAscending();
        int right = nextDescending();
        while(stLeft.empty()!=true && stRight.empty()!= true)
        {
            if(left + right < k)
            {
                left = nextAscending();
                cout<<"left is "<<left<<"\n";
            }
            else if(left + right > k)
            {
                right = nextDescending();
                cout<<"right is "<<right<<"\n";
            }
            else
            {
                if(left != right)
                    return true;
                if(left == right)
                    return false;
            }
        }
        return false;
        
        
        /*vector<int> inorder;
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
        return false;*/
    }
};