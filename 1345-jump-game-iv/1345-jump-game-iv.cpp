class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> mp;
        for(int i = 0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        vector<bool> vis(arr.size(), false);
        queue<int> q;
        q.push(0);
        int steps = 0;
        while(q.empty()!=true) {
           int size = q.size();
            while(size--> 0) {
                 
            int curr = q.front();
            q.pop();
            if(curr == arr.size()-1)
                return steps;
                vector<int> & connectedNode = mp[arr[curr]];
                connectedNode.push_back(curr-1);
                connectedNode.push_back(curr+1);
                for(auto elem:connectedNode) {
                    if(elem !=curr && elem >=0 && elem<arr.size() && !vis[elem] )
                    {
                        q.push(elem);
                        vis[elem]=true;
                    }
                }
                
                connectedNode.clear();
            }
            steps++;       
        }
        return -1;
    }
};