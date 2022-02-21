class Solution {
public:
    bool dfsFindOddCycle(vector<vector<int>>& graph, vector<bool> &visited, 
                         vector<bool> &dfsvisited, int curr, int cyclen, int parent)
    {
        visited[curr] = true;
        dfsvisited[curr] = true;
        for(auto it:graph[curr])
        {
            if(!visited[it])
            {
                cout <<"Traversing "<<it <<"\n";
                if(dfsFindOddCycle(graph, visited, dfsvisited ,it, cyclen+1, curr))
                    return true;
            }
            else if(it == parent)
            {
                continue;
            }
            else if(visited[it] && dfsvisited[it] )
            {
                int cycle = cyclen+1;
                cout <<"at "<<it<<"\n";
                cout <<"cycle length is "<<cycle<<"\n";
                if ((cycle)%2 != 0)
                    return true;
            }
        }
        cout<<"returning from "<<curr<<"\n";
        dfsvisited[curr]= false;
        return false;
        
    }
    
    bool bfsColoring(vector<vector<int>>& graph, vector<bool> &visited, 
                    vector<int> &color, int curr)
    {
        //using colors 0 and 1
        queue<int> q;
        q.push(curr);
        color[curr] = 0;
        visited[curr] = true;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            for(auto it: graph[curr])
            {
                if(color[it]==-1)
                {
                    //unvisited
                    color[it] = (color[curr]==0?1:0);
                    q.push(it);
                }
                else
                {
                    if(color[it]==0 && color[curr]==0)
                        return false;
                    else if (color[it]==1 && color[curr] == 1)
                        return false;
                }
            }
        }
        return true;
        
    }
    
    bool dfsColoring(vector<vector<int>>& graph, 
                    vector<int> &color, int curr, int parentColor)
    {
        if(color[curr] == -1)
        {
            color[curr] = !parentColor;
            for(auto it:graph[curr])
            {
                if(!dfsColoring(graph, color, it, !parentColor))
                    return false;
            }
        }
        else
        {
            if(color[curr]!= !parentColor)
            {
                return false;
            }

        }
        return true;
        
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        vector<bool> visited(graph.size(), false);
        vector<bool> dfsvisited(graph.size(), false);
        vector<int> color(graph.size(), -1);
        // graph is actually a adjency list
        for(int i = 0;i<graph.size();i++)
        {
            
            //if(!visited[i])
            if(color[i]==-1)
            {
                cout <<"starting point "<<i<<"\n";
                //if(dfsFindOddCycle(graph, visited, dfsvisited, i, 0, -1))
                //if(!bfsColoring(graph, visited, color, i))
                //    return false; //means coloring not possible
                if(!dfsColoring(graph, color, i, 1))
                    return false;
                //visited[i] = true;
            }
        }
        return true;
    }
};