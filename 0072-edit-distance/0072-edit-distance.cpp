class Solution {
public:
    int levenshteinDistance1(string str1, string str2, int i1, int i2, vector<vector<int>>& dp) 
    {
      if(i1 == str1.size()) return str2.size()-i2;
      if(i2 == str2.size())  return str1.size()-i1;
      if(dp[i1][i2]!=-1) return dp[i1][i2];
      if(str1[i1] == str2[i2]) return levenshteinDistance1(str1, str2, i1+1, i2+1, dp);
      else
      {
        return dp[i1][i2] = min(min(1+levenshteinDistance1(str1,str2,i1,i2+1, dp), // insert
                                    1+levenshteinDistance1(str1,str2,i1+1,i2+1, dp)), // replace
                                1+ levenshteinDistance1(str1,str2,i1+1,i2, dp) );  //delete    
      }

      //return -1;
    }
    int minDistance(string str1, string str2) {
        vector<vector<int>> dp(str1.size()+1, vector<int>(str2.size()+1, -1));
        return levenshteinDistance1(str1,str2,0,0, dp);
    }
    



};