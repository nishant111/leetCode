class Solution {
public:
    int count(vector<int>& data)
    {
        int count = 0;
        for(auto elem:data)
        {
            if(elem ==1)
                count++;
        }
        return count;
    }
    int minSwaps(vector<int>& data) {
        int l = 0;
        int r = 0;
        int ans = INT_MAX;
        int ones = count(data);
        if(ones == 0) return 0;
        int zeros = 0;
        while(r<data.size())
        {
            if(data[r] == 0)
            {
                zeros++;
            }
            
            if(r-l+1 == (ones))
            {
                ans = min(ans, zeros);
                if(data[l++] == 0)
                    zeros--;
            }
            r++;
        }
        return ans;
    }
};