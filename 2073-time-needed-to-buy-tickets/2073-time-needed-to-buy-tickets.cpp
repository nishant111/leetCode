class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int curr = 0;
        int n = tickets.size();
        int time = 0;
        while(tickets[k]!=0){
            if(tickets[curr%n]==0)
                curr++;
            else{
                tickets[curr%n] -= 1;
                curr++;
                time++;
            }
        }
        return time;
    }
};