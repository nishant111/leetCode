class Solution {
public:
    int dfs(int k, int w, vector<int>& profits, vector<int>& capital, int curr){
        if(k == 0)
            return w;
        if(curr == capital.size()){
            return w;
        }
        int p = 0;
        int np = 0;
        if(w >= capital[curr]){
            //try picking this up project
            p = dfs(k-1, w+profits[curr], profits, capital, curr+1);
        }
        
        //try skipping this project to maximize further
        np = dfs(k, w, profits, capital, curr+1);
        return max(p, np);
    }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        //return dfs(k, w, profits, capital, 0 );
        
        vector<pair<int, int>> proj;
        for(int i = 0;i<profits.size();i++){
            proj.push_back({capital[i], profits[i]});
        }
        sort(proj.begin(), proj.end());
        priority_queue<int> q;
        int pickCount = 0;
        int iter = 0;
        for(int i = 0;i<proj.size();i++ ){
            while(iter<proj.size() && w >= proj[iter].first){
                q.push(proj[iter].second);
                iter++;
            }
            // if cant afford any project
            if(q.empty())
                break;
            w += q.top();
            pickCount++;
            q.pop();
            if(pickCount == k)
                break;
        }
        return w;
    }
};