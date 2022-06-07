class Solution {
public:
    vector<int> diStringMatch(string s) {
        int low = 0;
        int hi = s.size();
        vector<int> ans;
        for(int i = 0;i<s.size();i++)
        {
            if(s[i] =='I')
            {
                ans.push_back(low++);
            }
            else
            {
                ans.push_back(hi--);
            }
        }
        ans.push_back(low);
        return ans;
    }
};