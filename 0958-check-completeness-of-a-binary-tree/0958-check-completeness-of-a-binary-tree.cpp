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
    bool levelOrder(TreeNode *root) {
        if(root == NULL)
            return true;
        queue<TreeNode *> q;
        q.push(root);
        bool hitNull = false;
        while(q.empty()!=true) {
            
            int size = q.size();
                TreeNode *curr = q.front();
                 q.pop();
                if(curr->left){
                    if(hitNull) return false;
                    q.push(curr->left);
                }
                else {
                    hitNull = true;
                }
                if(curr->right) {
                    if(hitNull) return false;
                    q.push(curr->right);
                }
                else {
                    hitNull=true;
                }
            

        }
        return true;
    }
    bool isCompleteTree(TreeNode* root) {
        return levelOrder(root);
    }
};