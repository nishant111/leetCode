class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string ans;
        vector<int> freq(2,0);
        for(auto elem:s){
            if (elem=='1'){
                freq[1]++;
            }
            else{
                freq[0]++;
            }
        }
        
        while(freq[1]>1){
            ans= "1" + ans;
            freq[1]--;
        }
        while(freq[0]>0){
            ans = ans + '0';
            freq[0]--;
        }
        ans = ans + '1';
        return ans;
    }
};