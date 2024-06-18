class Solution {
public:
    static bool comp(pair<int, int> a, pair<int, int> b){
        return a.first>=b.first;
    }
    void print(auto a){
        for(auto el:a){
            cout<<"{"<<el.first <<","<<el.second<<"} ";
        }
        cout<<"\n";
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>>pd;
        for(int i = 0;i<difficulty.size();i++){
            pd.push_back({profit[i], difficulty[i]});
        }
        
        sort(pd.begin(), pd.end(), comp);
        //print(pd);
        sort(worker.begin(), worker.end(), greater<int>());
        int wi = 0;
        int pdi = 0;
        int ans = 0;
        while(pdi<pd.size() && wi<worker.size()){
            if(worker[wi]>=pd[pdi].second){
                // can take this work
                ans += pd[pdi].first;
                // each worker takes at most one job
                wi++;
            }
            else{
                pdi++;
            }
        }
        return ans;
    }
};