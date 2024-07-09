class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double tw = 0;    //total wait time
        int chefIdleOn = -1;
        int timeTaken = 0;
        for(int i = 0;i<customers.size();i++){
            timeTaken = 0;
            if(chefIdleOn == -1 or chefIdleOn<customers[i][0]){
                timeTaken = customers[i][0] + customers[i][1];
            }    
            else{
                timeTaken = chefIdleOn + customers[i][1];
            }
            chefIdleOn = timeTaken;
            tw += timeTaken - customers[i][0];
        }
        
        return (double)tw/(double)customers.size();
    }
};