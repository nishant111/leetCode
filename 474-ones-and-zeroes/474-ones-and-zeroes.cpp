/*class Solution {
public:
    int countString(int m, int n,
                vector<string>& arr, int i)
{
    // Base Case if count of 0's or 1's
    // becomes negative
    if (m < 0 || n < 0) {
        return INT_MIN;
    }
 
    // If index reaches out of bound
    if (i >= arr.size()) {
        return 0;
    }
 
    // Initialize count of 0's and 1's
    // to 0 for the current state
    int zero = 0, one = 0;
 
    // Calculate the number of 1's and
    // 0's in current string
    for (char c : arr[i]) {
        if (c == '0') {
            zero++;
        }
        else {
            one++;
        }
    }
 
    // Include the current string and
    // recurr for the next iteration
    int x = 1 + countString(m - zero,
                            n - one,
                            arr, i + 1);
 
    // Exclude the current string and
    // recurr for the next iteration
    int y = countString(m, n, arr, i + 1);
 
    // Update the maximum of the above
    // two states to the current dp state
    return  max(x, y);
}
    int findMaxForm(vector<string>& strs, int m, int n) {
        return countString(m, n, strs, 0);
    }
};

*/

typedef vector<int> v1d;
typedef vector<v1d> v2d;
typedef vector<v2d> v3d;

class Solution {
public:
    
    int dfs(vector<string> & strs, int zeros, int ones, int curr, v3d &dp)
    {
        
        if(zeros<0 || ones<0) return INT_MIN;
        if(curr>=strs.size()) return 0;
        if(dp[curr][zeros][ones]!= -1) return dp[curr][zeros][ones];
        int countzero = 0;
        int countone = 0;
        for(int i = 0;i<strs[curr].size();i++)
        {
            if(strs[curr][i] == '1') countone++;
            else if(strs[curr][i] == '0') countzero++;
        }
        int pick = 1+dfs(strs, zeros - countzero, ones - countone, curr+1, dp);
        int nonpick = dfs(strs, zeros, ones, curr+1, dp);
        return dp[curr][zeros][ones] = max(pick, nonpick);
        
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        v3d dp(size+1, v2d(m+1, v1d(n+1, -1)));
        return dfs(strs, m, n, 0, dp);
    }
};