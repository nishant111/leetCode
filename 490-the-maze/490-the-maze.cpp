class Solution {
public:
    
    bool dfs(vector<vector<int>>& maze,int startr,int startc, vector<int>& dest, vector<vector<int>> &vis)
    {
        /*if(
            startc-1>=0 && (maze[startr][startc-1] == 1 ||
                            vis[startr][startc-1] == 1) &&
            startr+1<maze.size()
                        && (maze[startr+1][startc] == 1 ||
                            vis[startr+1][startc] == 1) &&
            startc+1<maze[0].size()
                        && (maze[startr][startc+1] == 1 ||
                            vis[startr][startc+1] == 1) &&
            startr-1>=0 && (maze[startr-1][startc] == 1 ||
                            vis[startr-1][startc] == 1)
            
        )
             
            {
                // ball stuck no path forward
                return false;
            }*/
        
            if(vis[startr][startc] == 1)
            {
                return false;
            }
            
            else if(startr == dest[0] && startc == dest[1])
            {
                return true;
            }
            // mark visited
            vis[startr][startc] = 1;
            int tmpr = startr;
            int tmpc = startc;
            //roll left
            while(tmpc-1>=0 && maze[tmpr][tmpc-1]!=1)
            {
                tmpc--;
            }
            if(dfs(maze, tmpr, tmpc, dest, vis)) return true;
            tmpr = startr;
            tmpc = startc;
            //roll down
            while(tmpr+1<maze.size() && maze[tmpr+1][tmpc]!=1)
            {
                tmpr++;
            }
            if(dfs(maze, tmpr, tmpc, dest, vis)) return true;
            tmpr = startr;
            tmpc = startc;
            //roll right
            while(tmpc+1<maze[0].size() && maze[tmpr][tmpc+1]!=1)
            {
                tmpc++;
            }
            if(dfs(maze, tmpr, tmpc, dest, vis)) return true;
            tmpr = startr;
            tmpc = startc;
            //roll up
            while(tmpr-1>=0 && maze[tmpr-1][tmpc]!=1)
            {
                tmpr--;
            }
            if(dfs(maze, tmpr, tmpc, dest, vis)) return true;
            return false;
    }
    
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        vector<vector<int>> vis(maze.size(), vector<int> (maze[0].size(), 0));
        if(dfs(maze, start[0], start[1], destination, vis))
            return true;
        return false;
    }
};