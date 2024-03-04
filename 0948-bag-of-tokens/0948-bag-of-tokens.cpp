class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if(tokens.size()==0) return 0;
        sort(tokens.begin(), tokens.end());
        int currScore = 0;
        int tradeForScore = 0;
        int tradeForPower = tokens.size()-1;
        int ans = INT_MIN;
        while(tradeForScore<=tradeForPower){
            if(currScore == 0){
                //special starting case
                if(power >= tokens[tradeForScore]){
                    power -= tokens[tradeForScore++];
                    currScore++;
                }
                else{
                    // cant do much here
                    return 0;
                }
            }
            else{
                if(power >= tokens[tradeForScore]){
                    power -= tokens[tradeForScore++];
                    currScore++;
                }
                else{
                    if (currScore>=1){
                        // need to get more power
                        power += tokens[tradeForPower--];
                        currScore--;
                    }
                }
            }
            ans = max(ans, currScore);
        }
        return ans;
    }
};