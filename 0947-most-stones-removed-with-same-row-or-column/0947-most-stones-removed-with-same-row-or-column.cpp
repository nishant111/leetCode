class Solution {
public:
    void dfs(vector<int> adj[],int i,vector<bool>& vis)
    {
        vis[i]=true;
        
        for(auto elem:adj[i])
        {
            if(vis[elem] == false)
                dfs(adj, elem, vis);
        }
        return;
    }
    int removeStones(vector<vector<int>>& stones) {
        vector<int> adj[stones.size()];
        for(int i = 0;i<stones.size();i++)
        {
            for(int j = i+1;j<stones.size();j++)
            {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<bool> vis(stones.size(), false);
        
        int connectedComp = 0;
        
        for(int i = 0;i<stones.size();i++)
        {
            if(vis[i]==false)
            {
                connectedComp++;
                dfs(adj, i, vis);
            }
        }
        return stones.size()-connectedComp;
    }
};

/*
class Solution {
public:
    
    bool static comp (vector<int> &A, vector<int> &B)
    {
        return A[0]<B[0];
    }
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, int> mr;
        unordered_map<int, int> mc;
        
        for(auto elem:stones)
        {
            mr[elem[0]]++;
            mc[elem[1]]++;
        }
        
        sort(stones.begin(), stones.end(), comp);
        
        int count = 0;
        for(int i = stones.size()-1;i>=0 ; i--)
        {
            bool removed = false;
            // check if there are more than one( including self) stone in same row.
            if(mr.find(stones[i][0])!=mr.end() && mr[stones[i][0]]>1)
            {
                // remove the stone
                mr[stones[i][0]]--;
                mc[stones[i][1]]--;
                count++;
                removed = true;
            }
            if(mc.find(stones[i][1])!=mc.end() && mc[stones[i][1]]>1)
            {
                mc[stones[i][0]]--;
                mc[stones[i][1]]--;
                if(!removed)
                    count++;
                removed = true;
            }
        }
        return count;
    }
};
*/