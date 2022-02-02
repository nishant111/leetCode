#include <bits/stdc++.h>

using namespace std;

class point{
  public:
    int x;
    int y;
};


class Solution {
public:
    deque <point> q;
    int pushCount = 0;
    int time = 0;int rotton = 0;int orange=0;
    int orangesRotting(vector<vector<int>>& grid) 
    {
        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {
                    //pushing t=0 rotton oranges
                    cout<<"Pushing "<<i << ","<<j <<"\n";
                    point p = {i,j};
                    q.push_back(p);
                    rotton++;
                    orange++;
                }
                else if(grid[i][j]==1)
                    orange++;
            }
        }
        cout <<"Oranges are "<<orange<<"\n";
        if(orange == 0) return 0;
        if (q.size()==0)
            return -1;
        while(q.empty()!=true)
        {
            int size = q.size();
            cout <<"Queue size is "<<size<<"\n";
            for(int i = 0;i<size ;i++)
            {
                point target = q.front();
                q.pop_front();
                if((target.x) -1 >= 0 && grid[target.x-1][target.y]== 1)
                {
                    q.push_back({target.x-1, target.y});
                    grid[target.x-1][target.y] = 2;
                    rotton++;
                    cout<<target.x-1<<" " <<target.y<<"Rotten on time"<<time<<"\n";
                }
                if((target.x) +1 < grid.size()  && grid[target.x+1][target.y]== 1)
                {
                    q.push_back({target.x+1, target.y});
                    grid[target.x+1][target.y] = 2;
                    rotton++;
                    cout<<target.x+1<<" " << target.y<<"Rotten on time"<<time<<"\n";
                }
                if((target.y) - 1>= 0  && grid[target.x][target.y-1]== 1)
                {
                    q.push_back({target.x, target.y-1});
                    grid[target.x][target.y-1] = 2;
                    rotton++;
                    cout<<target.x<<" " <<target.y-1<<" Rotten on time"<<time<<"\n";
                }
                if((target.y) + 1< grid[0].size()  && grid[target.x][target.y+1]== 1)
                {
                    q.push_back({target.x, target.y+1});
                    grid[target.x][target.y+1] = 2;
                    rotton++;
                    cout<<target.x<<" " <<target.y+1<<"Rotten on time"<<time<<"\n";
                }
            }
            time++;
        }
        cout <<"Rotton are "<<rotton;
        if(rotton == orange)
            return time-1;
        else  if(orange == 0)
            return 0;
        return -1;
    }
};