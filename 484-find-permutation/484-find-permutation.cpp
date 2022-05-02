class Solution {
public:
    vector<int> findPermutation(string s) {
        int len = s.size();
        vector<int> ans(len+1);
        for(int i = 0;i<ans.size();i++)
        {
            ans[i] =i+1; 
        }
        
        int start = 0;
        int end = 0;
        for(int i= 0;i<=s.size();i++)
        {
            if(s[i] == 'D')
            {
                start = i;
                while(i<=s.length() && s[i]=='D')
                {
                    i++;
                }
                reverse(ans.begin()+start, ans.begin()+i+1);
                
            }
            else if(s[i]=='I')
            {
                continue;
            }
        }
         return ans;
    }
};