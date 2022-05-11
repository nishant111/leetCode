class Solution {
public:
    int totCount = 0;
    void dfs(int n, string vow, int curr, int count )
    {
        if(count == n)
        {
            totCount++;
            return;
        }
            
        for(int i = curr;i<vow.size();i++)
        {
            dfs(n, vow, i, count+1);
        }
    }
    int countVowelStrings(int n) {
        string vow= "aeiou";
        int count = 0;
        dfs(n, vow, 0, count);
        return totCount;
    }
};