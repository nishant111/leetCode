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

int max(int a,int b) 
{           
    return a>=b?a:b;
}

class Solution {
public:
    int dfs(TreeNode *root, int &maxi)
    {
        if(root == NULL) return 0;
        int left = max(0,dfs(root->left, maxi));
        int right = max(0,dfs(root->right, maxi));
        //save max with curve/split in global var
        //int tmp = max(, root->val);
        maxi = max(left+right+(root->val), maxi);
        //return without curve/split;
        int tmp = max(left,right);
        return (tmp + root->val);
        
    }
    int maxPathSum(TreeNode* root) {
         if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return root->val;
        int maxi = INT_MIN;
        int rval = dfs(root, maxi);
        if(rval>maxi) return rval;
        return maxi;
    }
};









/*int MAX(int a,int b,int c) 
{           if(a>=b && a>=c ) 
            return a;                
            else if(b>=a && b>=c ) 
            return    b;                
            else if(c>=b && c>=a ) 
             return   c;                
            else
                return -1;
}
class Solution {
public:
    int dfs(TreeNode *root, int &maxYet)
    {
        if(root == NULL) return 0;
        int left = MAX(0, dfs(root->left, maxYet),INT_MIN);
        int right = MAX(0,dfs(root->right, maxYet), INT_MIN);
        cout <<"left is "<<left<<"\n";
        cout <<"right is "<<right<<"\n";
        cout <<"root->val is"<<root->val<<"\n";
        
        //max with split
        maxYet = MAX(left+right + (root->val), maxYet, INT_MIN);
        
        //max without split
        //int tmpMax =  MAX(left, right, root->val);
        int tmpMax = MAX(left, right, INT_MIN);
        cout<<"tmpMax yet is "<<tmpMax<<"\n";
        cout<<"maxYet  is "<<maxYet<<"\n";
        return tmpMax + root->val;
    }
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return root->val;
        int maxYet = INT_MIN;
        int ans = dfs(root, maxYet);
        if(ans > maxYet) return ans;
        return maxYet;
    }
};*/