class Solution {
public:
    
    static bool comp(vector<int> &a, vector<int> &b)
    {
        if(a[0] > b[0])
        {
            return true;
        }
        else if(a[0]<b[0])
        {
            return false;
        }
        else
        {
            return (a[1]<b[1]);
        }
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), comp);
        
        vector<vector<int>> ans;
        for(auto elem:people)
        {
            int idx = elem[1];
            ans.insert(ans.begin() + idx, elem);
            
        }
        return ans;
        
    }
};