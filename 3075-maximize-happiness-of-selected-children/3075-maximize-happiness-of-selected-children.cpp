class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int decrementor = 0;
        sort(happiness.begin(), happiness.end(), greater<int>());
        int curr=0;
        long long ans = 0;
        while(curr<happiness.size() && k>0){
            int actualHappiness = happiness[curr];
            if(happiness[curr]>0)
            {
                actualHappiness = actualHappiness-decrementor;
            }
            //cout<<"happiness["<<curr<<"] is "<< actualHappiness;
            if(actualHappiness>0){
                ans += actualHappiness;
                decrementor++;
                k--;
            }
            curr++;
        }
        return ans;
    }
};