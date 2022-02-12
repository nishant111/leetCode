/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode TreeNode;
    int find(int *arr, int targ, int size)
    {
        for(int i = 0;i<size;i++)
        {
            if(arr[i] == targ)
                return i;
        }
        return -1;
    }
 TreeNode* dfs(int *preorder, int preStart, int preEnd, int *inorder, int inStart, int inEnd, int countL, int countR, int inorderSize)
    {
        if( preEnd < preStart  || inEnd < inStart ) return NULL;
        //if(countL == 0 || countR == 0  ) return NULL;
        // if(preStart<0 || preStart > preEnd || inStart > inEnd)
        //return NULL;
        TreeNode *curr = (TreeNode*)malloc(sizeof(TreeNode));
        curr -> val = preorder[preStart];
        int inorderIndex = find(inorder,curr->val,inorderSize);
        //cout << "inorderIndex is" <<inorderIndex <<"\n";
         countL = (inorderIndex - 1) - inStart + 1;
        //if(countL <= 0) return NULL;
         countR = inEnd - (inorderIndex + 1) + 1;
        //if(countR <= 0 ) return NULL;
        curr->left = dfs(preorder, preStart+1, preStart+countL, 
                         inorder, inStart ,inorderIndex-1,
                         countL, countR, inorderSize);
        curr->right = dfs(preorder, preStart + countL + 1,  preEnd,
                         inorder, inorderIndex + 1, inEnd,
                         countL, countR, inorderSize);
        /*if(curr->left && curr->right)
        cout<< curr->val <<" left child is "<<curr->left->val <<" & right child is "<<curr->right->val<<"\n";
        else
            cout<< curr->val <<" left child is NULL "<<" & right child is NULL"<<"\n";*/
        return curr;
    }
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    return( dfs(preorder, 0, preorderSize-1, inorder, 0, inorderSize-1, -1, -1, inorderSize) );
}





/*#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    TreeNode* dfs(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &m , int countL, int countR)
    {
        if( preEnd < preStart  || inEnd < inStart ) return NULL;
        //if(countL == 0 || countR == 0  ) return NULL;
        // if(preStart<0 || preStart > preEnd || inStart > inEnd)
        //return NULL;
        TreeNode *curr = (TreeNode*)malloc(sizeof(TreeNode));
        curr -> val = preorder[preStart];
        int inorderIndex = m[curr->val];
        cout << "inorderIndex is" <<inorderIndex <<"\n";
         countL = (inorderIndex - 1) - inStart + 1;
        //if(countL <= 0) return NULL;
         countR = inEnd - (inorderIndex + 1) + 1;
        //if(countR <= 0 ) return NULL;
        curr->left = dfs(preorder, preStart+1, preStart+countL, 
                         inorder, inStart ,inorderIndex-1,
                         m, countL, countR);
        curr->right = dfs(preorder, preStart + countL + 1,  preEnd,
                         inorder, inorderIndex + 1, inEnd,
                         m, countL, countR);
        if(curr->left && curr->right)
        cout<< curr->val <<" left child is "<<curr->left->val <<" & right child is "<<curr->right->val<<"\n";
        else
            cout<< curr->val <<" left child is NULL "<<" & right child is NULL"<<"\n";
        return curr;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> m; //map inorderValue to inorderIndex
        for(int i = 0;i<inorder.size();i++)
        {
            m[inorder[i]] = i;
        }
        return( dfs(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, m, -1, -1) );
       
    }
};

int find(int targ, int *inorder, int size)
{
    for(int i = 0;i<size; i++)
    {
        if(inorder[i] == targ)
            return i;
    }
    return -1;
}

typedef struct TreeNode treeNode;
treeNode * dfs(int *preOrder, int preStart, int preEnd,
         int *inOrder, int inStart, int inEnd, int inSize)
{
    if(preStart<0 || preStart > preEnd || inStart > inEnd)
        return NULL;
    
    treeNode * root = calloc(1, sizeof(treeNode));
    root->val = preOrder[preStart];
    int idx = find(root->val, inOrder, inSize);
    int numsLeft = idx - inStart;
    //int numsRight = inEnd - idx;
    root->left = dfs(
        preOrder, preStart+1, preStart + numsLeft,
        inOrder, inStart, idx-1, inSize);
    root->right = dfs(
        preOrder, preStart+numsLeft+1, preEnd,
        inOrder, idx+1, inEnd, inSize );
    return root;
}


struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    int map[6000];
    
    return (dfs(preorder, 0,  preorderSize-1, 
       inorder,0, inorderSize-1, inorderSize ) );
}*/