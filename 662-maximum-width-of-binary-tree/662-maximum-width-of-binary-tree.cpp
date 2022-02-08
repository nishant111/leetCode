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
#define MAX(a,b) (a>b?a:b)
class Solution {
public:
    void dfs(TreeNode *root, map<int, int> &left_m, int &ans,int level, int val)
    {
        if (root == NULL) return;
        if(left_m.find(level)==left_m.end())
        {
            left_m[level] = 2*level+1;
        }
    }
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<unsigned int, TreeNode*>> q;
        q.push({0, root});
        int maxWidth=1;
        //dfs(root, m, ans,0,0);
        while(q.empty()!=true)
        {
            int size = q.size();
            for(int i = 0;i<size;i++)
            {
                auto curr = q.front();
                q.pop();
                if(curr.second->left)
                {
                    cout <<"Pushing node count  as "<<curr.first*2 <<"for " <<curr.second->left->val<<"\n";
                    q.push({curr.first*2, curr.second->left});
                }
                if(curr.second->right)
                {
                    cout <<"Pushing node count  as "<<curr.first*2+1 <<"for " <<curr.second->right->val<<"\n";
                    q.push({curr.first*2+1, curr.second->right});
                }
            }
            // when pushed all the available node at the level, calculate width
            if(q.size()>0)
                maxWidth = MAX(maxWidth, q.back().first - q.front().first + 1);
        }
        
        return maxWidth;
    }
};