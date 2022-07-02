class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int n = horizontalCuts.size();
        int m = verticalCuts.size();
        
        int maxH = max(horizontalCuts[0], h- *(horizontalCuts.rbegin() ));
        int maxW = max(verticalCuts[0], w- *(verticalCuts.rbegin() ));
        
        for(int i = 1;i<horizontalCuts.size();i++)
        {
            maxH = max(maxH , horizontalCuts[i] - horizontalCuts[i-1]);
        }
        
        for(int i = 1;i<verticalCuts.size();i++)
        {
            maxW = max(maxW , verticalCuts[i] - verticalCuts[i-1]);
        }
        
        return (int)(((long)maxH * (long)maxW)%1000000007);
    }
};