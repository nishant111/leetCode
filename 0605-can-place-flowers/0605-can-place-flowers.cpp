class Solution {
public:
    bool canPlace(int curr, vector<int>& flowerbed) 
    {
        if (curr == 0) {
            return flowerbed[curr+1] == 0;
        }
        if(curr == flowerbed.size()-1) {
            return flowerbed[curr-1] == 0;
        }

        return flowerbed[curr-1] == 0 && flowerbed[curr+1] == 0;
    }
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int planted=0;
        if(flowerbed.size()==1){
            if(flowerbed[0] == 0) return n<=1;
            else return n==0;
        }
        for(int i = 0;i<flowerbed.size();i++) {
            if(flowerbed[i] == 0 && canPlace(i, flowerbed)) {
                flowerbed[i] = 1;
                planted++;
            }
        }
        if(n<=planted) return true;
        return false;
    }
};