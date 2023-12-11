class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int count = arr.size()/4;
        int ans = -1;
        int c = 0;
        for(int i = 0;i<arr.size();i++){
            if(ans != arr[i]){
                c=1;
                ans = arr[i];
            }
            else if(ans == arr[i]){
                c++;    
            }
            if(c>count){
                return ans;
            }
        }
        return -1;
    }
};