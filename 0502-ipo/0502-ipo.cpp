class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> proj;

        for (int i = 0;i<profits.size();i++){
            proj.push_back({capital[i], profits[i]});
        }
        priority_queue<int> pq;
        sort(proj.begin(), proj.end());
        int ptr = 0;
        for(int i = 0;i<k;i++){
            while(ptr <proj.size() && proj[ptr].first<=w){
                pq.push(proj[ptr].second);
                ptr++;
            }
            if(pq.empty())
                break;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};