class Solution {
public:
    int maxArea(vector<int>& height) {
        // start with left and right ptr
        // calculate area. and maximize
        // move ptr at the lesser or equal height
        int ans=0;
        int left = 0;
        int right = height.size()-1;
        while(left<right)
        {
            int tow = min(height[left], height[right]);
            int area = ( tow * (right - left));
            ans = max(ans, area); 
            if(height[left]<height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return ans;
    }
};