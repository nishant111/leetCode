class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // find max value in distance array , if INT_MAX return -1;
        
        vector<pair<int, int>> adj[n+1];
        for(int i = 0;i<times.size();i++)
        {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        
        vector<int> distance(n+1, INT_MAX);
        queue<int> q;
        q.push(k);
        distance[k] = 0;
        
        while(q.empty()!=true)
        {
            int curr = q.front();
            q.pop();
            
            for(auto it : adj[curr])
            {
                int d = distance[curr] + it.second;
                int node = it.first;
                if( d<distance[node])
                {
                    distance[node] =d;
                    q.push(node);
                }
            }
        }
        int ans= distance[1];
        for(int i = 1;i<distance.size();i++)
        {
            cout <<"d is" <<distance[i]<<"\n";
            if(ans<distance[i])
                ans = distance[i];
        }
        if (ans==INT_MAX)
            return -1;
        return ans;
        
    }
};