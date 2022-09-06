/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<Node*> q;
        q.push(root);
        while(q.empty()!=true)
        {
            int size = q.size();
            vector<int> tmpAns;
            
            while(size> 0)
            {
                Node *curr = q.front();
                tmpAns.push_back(curr->val);
                q.pop();
                size--;
                for(auto it:curr->children)
                {
                    q.push(it);
                }
            }
            ans.push_back(tmpAns);
        }
        return ans;
    }
};