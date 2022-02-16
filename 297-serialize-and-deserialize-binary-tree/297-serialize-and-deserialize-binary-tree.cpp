/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <bits/stdc++.h>
#include <string.h>
using namespace std;
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root ==NULL) return "";
        queue <TreeNode*> q;
        string levelOrder ="";
        q.push(root);
        char a[10];
        sprintf(a, "%d,", root->val);
        levelOrder.append(a);
        while(q.empty()!=true)
        {
                        
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left)
            {
                q.push(curr->left);
                sprintf(a, "%d,", curr->left->val);
                levelOrder.append(a);
            }
            else if (!curr->left)
            {
                levelOrder.append("#,");
            }   
            if(curr->right)
            {
                q.push(curr->right);
                sprintf(a, "%d,", curr->right->val);
                levelOrder.append(a);
            }
            else if(!curr->right)
            {
                levelOrder.append("#,");
            }
            
        }
        cout << levelOrder;
        return levelOrder;
    }
    
    TreeNode * create (int data)
    {
        TreeNode * curr = (TreeNode*) calloc(1, sizeof(TreeNode));
        curr -> val = data;
        return curr;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        queue<TreeNode*> q;
        int idx = data.find(',');
        int tmp = stoi(data.substr(0, idx));
        cout<<"tmp is "<<tmp<<"\n";
        TreeNode *root = create(tmp);
        data = data.substr(idx+1, data.length());
        cout<<"data is "<<data<<"\n";
        q.push(root);
        while(q.empty()!=true && data.size()!=0)
        {
            TreeNode* curr = q.front();
            cout <<"Processing "<<curr->val<<"\n";
            q.pop();
            /* left child */
            int idx = data.find(',');
            int tmp;
            if(data.substr(0, idx)[0] != '#')
                tmp = stoi(data.substr(0, idx));
            else
                tmp =INT_MIN;
          //  cout<<"tmp is "<<tmp<<"\n";
            if(tmp == INT_MIN)
            {
                cout << "left child of "<<curr->val <<" is " << "NULL" <<"\n";
                curr->left = NULL;
            }
            else
            {
                curr->left = create(tmp);
                cout << "left child of "<<curr->val <<" is " << tmp <<"\n";
                 q.push(curr->left);
            }
            //q.pop();
            data = data.substr(idx+1, data.length());
           // cout<<"data is "<<data<<"\n";
           
            
            /* right child */
             idx = data.find(',');
            if(data.substr(0, idx)[0] != '#')
                tmp = stoi(data.substr(0, idx));
            else
                tmp =INT_MIN;
          //  cout<<"tmp is "<<tmp<<"\n";
            if(tmp ==INT_MIN)
            {
                cout << "Right child of "<<curr->val <<" is " << "NULL" <<"\n";
                
                curr->right =NULL;
            }
            else
            {
                curr->right = create(tmp);
                cout << "right child of "<<curr->val <<" is " << tmp <<"\n";
                q.push(curr->right);
            }
           
            data = data.substr(idx+1, data.length());
         //   cout<<"data is "<<data<<"\n";
            
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));