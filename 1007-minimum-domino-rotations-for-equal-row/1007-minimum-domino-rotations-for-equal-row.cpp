class Solution {
public:
    int tryPossibleMatch(vector<int>& tryMatchArr, vector<int>& otherArr, int matchVal)
    {
        int swapCount = 0;
        for(int i = 0; i<tryMatchArr.size();i++)
        {
            if(tryMatchArr[i] != matchVal )
            {
                if(otherArr[i] == matchVal)
                {
                    swapCount++;
                }
                else
                    return INT_MAX;
            }
        }
        return swapCount;
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int swapCount = 0;
        int matchVal = -1;
            int ans = INT_MAX ;
           ans =  min(tryPossibleMatch(tops, bottoms, tops[0]),
                   tryPossibleMatch(tops, bottoms, bottoms[0]));
            ans = min(ans, tryPossibleMatch(bottoms, tops, bottoms[0]));
            ans = min(ans, tryPossibleMatch(bottoms, tops, tops[0]));
            if(ans == INT_MAX) return -1;
            else return ans;
    }
};