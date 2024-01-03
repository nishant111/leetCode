class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int count = 0;
        int prevCount = 0;
        for(int i = 0;i<bank.size();i++){
            int currCount = 0;
            for(int j = 0;j<bank[0].size();j++){
                if(bank[i][j]=='1')
                    currCount++;
            }
            if(currCount > 0){
                count += prevCount * currCount;
                prevCount = currCount;
            }
        }
        return count;
    }
};