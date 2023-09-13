class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size()==1) return 1;
        vector<int> candy(ratings.size(), 1);
        // move left to right , ensures correctness w.r.t left ngb
        for(int i = 1;i<ratings.size();i++){
            if(ratings[i] < ratings[i-1]){
                while(candy[i-1]<=candy[i]){
                    candy[i-1]=candy[i]+1;

                }
            }
            else if(ratings[i] > ratings[i-1]){
                while(candy[i]<=candy[i-1])
                    candy[i]=candy[i-1]+1;
            }
            
        }
        
        // move right to left , ensures correctness w.r.t right ngb
        for(int i = ratings.size()-2;i>=0;--i){
            if(ratings[i] < ratings[i+1]){
                //while(candy[i+1]<=candy[i])
                    candy[i+1] =max(candy[i+1],candy[i]+1);

            }
            else if(ratings[i] > ratings[i+1]){
                //while(candy[i]<=candy[i+1])
                    candy[i] = max(candy[i],candy[i+1]+1);
            }

        }
        int sum = 0;
        for(auto el:candy){
            sum+=el;
        }
        return sum;
    }
};