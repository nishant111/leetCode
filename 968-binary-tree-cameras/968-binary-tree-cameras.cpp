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
    int camera = 0;
    enum coverage {hasCamera, covered, pleaseCover};
    
    coverage dfs(TreeNode* root, int &camCount)
    {
        if(root == NULL)
            return covered;
        coverage left = dfs(root->left, camCount);
        coverage right = dfs(root->right, camCount);
        
        if(left==pleaseCover || right==pleaseCover)
        {
            camCount++;
            return (hasCamera);
        }
        
        if(left == hasCamera || right == hasCamera)
        {
            return covered;
        }
        return (pleaseCover);
    }
    
    
    int minCameraCover(TreeNode* root) {
        if(root->left==NULL && root->right == NULL) return 1;
        int camCount = 0;
        dfs(root, camCount)==pleaseCover?++camCount:camCount;
        return camCount;
        
    }
};