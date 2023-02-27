/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

*/
class Solution {
public:
    Node * dfs(vector<vector<int>> & grid, int rs, int re, int cs, int  ce){
        if(rs > re || cs > ce){
            return NULL;
        }

        bool isLeaf = true;
        int val = grid[rs][cs];
        for(int i = rs;i<=re;i++){
            for(int j = cs;j<=ce;j++){
                if(grid[i][j] != val){
                    isLeaf = false;
                    break;
                }
            }
        }
        if(isLeaf){
            return new Node(val, true);
        }
        int rm = (rs+re)/2;
        int cm = (cs+ce)/2;
        Node * topLeft = dfs(grid, rs, rm, cs, cm);
        Node * topRight = dfs(grid, rs, rm, cm+1, ce);
        Node * bottomLeft = dfs(grid, rm+1, re, cs, cm);
        Node * bottomRight = dfs(grid, rm+1, re, cm+1, ce);

        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }
    Node* construct(vector<vector<int>>& grid) {
        return  dfs(grid, 0, grid.size()-1, 0, grid.size()-1);
    }
};