class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for(auto elem : s)
        {
            freq[elem-'a']++;
        }
        
        unordered_set<int> seen;
        int count = 0;
        for(int i = 0;i<freq.size();i++)
        {
            if(freq[i]!= 0 && seen.find(freq[i])== seen.end())
            {
                seen.insert({freq[i]});
            }
            else
            {
                while(freq[i]!= 0 && seen.find(freq[i]) != seen.end())
                {
                    freq[i]--;
                    count++;
                }
                if(freq[i]>0)
                {
                    seen.insert({freq[i]});
                }
                
            }
        }
        return count;
    }
};