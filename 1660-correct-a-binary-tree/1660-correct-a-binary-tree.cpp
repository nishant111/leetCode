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
    /* bfs avg case is better
    worst case in O(n), and space is O(n) worst case. */
    TreeNode* correctBinaryTree(TreeNode* root) {
        queue<TreeNode *> q;
        unordered_map<TreeNode*, TreeNode*> m;
        m[root] = NULL;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left)
            {
                m[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right)
            {
                if(m.find(curr->right)!=m.end())
                {
                    //curr is invalid
                    if(m[curr]->left == curr)
                    {
                        m[curr]->left = NULL;
                        return root;
                    }
                    else 
                    {
                        m[curr]->right = NULL;
                        return root;
                    }
                    
                }
                m[curr->right] = curr;
                q.push(curr->right);
            }
        }
        
        return root;
    }
};