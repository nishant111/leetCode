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
    TreeNode * dfs(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd,int poStart, int poEnd, unordered_map<int ,int> &mi ) {
        if(inStart>inEnd || poStart>poEnd || poEnd >= postorder.size())
            return NULL;
        TreeNode *root = new TreeNode(postorder[poEnd]);
        int inorderIdx = mi[postorder[poEnd]];
        int leftSize = inorderIdx - inStart;
        int rightSize = inEnd - inorderIdx;
        if(leftSize)
            root -> left = dfs(inorder, postorder, inStart, inorderIdx-1, poStart, poEnd - (rightSize) -1, mi);
        if(rightSize)
            root->right = dfs(inorder, postorder, inorderIdx+1,inEnd, poEnd - rightSize, poEnd-1, mi);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int ,int> mi;
        unordered_map<int, int> mp;
        int m = inorder.size()-1;
        int n = postorder.size()-1;
        for(int i = 0;i<inorder.size();i++) {
            mi[inorder[i]] = i;
        }
        return dfs(inorder, postorder, 0, m , 0 , n , mi);
    }
};