class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return (a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]);
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        
        sort(properties.begin(), properties.end(), comp);
        int weakCount = 0;
        int maxDef = 0;
        for(int i =properties.size()- 1;i>=0;i--)
        {
            
            if( properties[i][1]<maxDef)
                weakCount++;
            maxDef = max(maxDef, properties[i][1]);
        }
        return weakCount;
    }
};