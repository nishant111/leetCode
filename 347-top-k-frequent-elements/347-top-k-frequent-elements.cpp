class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map <int, int> m;
        for(auto elem:nums)
        {
            m[elem]++;
        }
        
        vector<vector<int>> bucket(nums.size()+1);
        
        for(auto i:m)
        {
            bucket[i.second].push_back(i.first);
        }
        
        for(int i = bucket.size()-1;i>=0;i--)
        {
            if(bucket[i].size()>0)
            {
                for(auto elem:bucket[i])
                    ans.push_back(elem);
            }
            if(ans.size()==k)
            {
                break;
            }
        }
        return ans;
    }
};