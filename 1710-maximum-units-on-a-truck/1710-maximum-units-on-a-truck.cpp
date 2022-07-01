class Solution {
public:
    static bool comp(vector<int> &A, vector<int> &B)
    {
        return (A[1]>B[1]);
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), comp);
        int ans =  0;
        int rem = truckSize;
        for(int i = 0;i<boxTypes.size();i++)
        {
            int boxCount = min(truckSize, boxTypes[i][0]);
            ans += boxCount * boxTypes[i][1];
            truckSize -= boxCount;
            if(truckSize == 0) break;
        }
        return ans;
    }
};
