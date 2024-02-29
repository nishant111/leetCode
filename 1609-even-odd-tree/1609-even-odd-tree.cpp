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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = -1;
        while(!q.empty()){
            level++;
            int size = q.size();
            bool evenLevel = (level%2 == 0);
            int prevVal = (evenLevel==false?INT_MAX:0);
            while(size-->0){
                TreeNode *curr = q.front();
                q.pop();
                // even value and even level is not allowed
                if (evenLevel && curr->val%2==0)
                    return false;
                if( evenLevel && curr->val<=prevVal)
                    return false;
                // odd value at odd level not allowed
                if (!evenLevel && curr->val%2!=0)
                    return false;
                // odd level does'nt allowe increasing seq
                if( !evenLevel && curr->val>=prevVal)
                    return false;
                prevVal = curr->val;
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
        }
        return true;
    }
};