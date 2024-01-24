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
    void dfs(TreeNode *root, vector<int> & freq, int &ans){
        if(root == NULL)
            return;
        freq[root->val]++;
        cout<<"val "<<root->val<<"\n";
        cout<<"freq "<<freq[root->val]<<"\n";
        if(root->left == NULL && root->right == NULL){
            cout<<root->val<< " is leaf \n";
            int cnt = countOdd(freq);
            if(cnt <= 1)
                ans++;
            freq[root->val]--;
            return;
        }
        dfs(root->left, freq, ans);
        dfs(root->right, freq, ans);
        freq[root->val]--;
        return;
    }
    int countOdd(const vector<int>& digits) {
        int cnt = 0;
        
        for (int i = 1; i < 10; ++i) {
            if ((digits[i]) & 1) cnt++;
        }
        return cnt;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        if(root->left == NULL && root->right == NULL) return 1;
        vector<int> freq(10,0);
        int ans = 0;
        dfs(root, freq, ans);
        return ans;
    }
};