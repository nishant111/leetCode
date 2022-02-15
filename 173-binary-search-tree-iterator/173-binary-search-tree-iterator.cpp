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
class BSTIterator {
public:
    stack <TreeNode*> st;
    BSTIterator(TreeNode* root) {
        TreeNode *curr = root;
        // push entire left leg
        // while doing next we will follow inorder rules
        while(curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
    }
    
    int next() {
        TreeNode* curr = st.top();
        int rtval = curr->val;
        if(curr->right)
        {
            // there exists a right leg, need to push that into stack
            st.pop();
            curr = curr->right;
            while(curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
        }
        else
        {
            // no right leg simply pop
            st.pop();
        }
        return rtval;
    }
    
    bool hasNext() {
        if(st.size()>0) return true;
        else 
            return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */