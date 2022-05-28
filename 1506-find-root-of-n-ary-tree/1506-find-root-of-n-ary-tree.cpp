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
    
    int dfs(Node *root, unordered_map <Node*, int> &nodeMap, int targ)
    {
        if(nodeMap.find(root)!=nodeMap.end())
        {
            return nodeMap[root];
        }
        if(root->children.size() == 0)
        {
            nodeMap.insert({root, 1});
            return 1;
        }
        
        int totSize = 0;
        for(auto elem: root -> children)
        {
            int size;
            if(nodeMap.find(elem) != nodeMap.end())
            {
                size = nodeMap[elem];
            }
            else
            {
                size = dfs(elem, nodeMap, targ);
            }
            totSize += size;

        }
        nodeMap.insert({root, totSize+1});
        
        return totSize+1;
        
    }
    
    Node* findRoot(vector<Node*> tree) {
        unordered_map <Node*, int> nodeMap;
        for(int i = 0;i<tree.size();i++)
        {
            int ans = dfs(tree[i], nodeMap, tree.size());
            if(ans == tree.size())
                return tree[i];
        }
        return NULL;
    }
};