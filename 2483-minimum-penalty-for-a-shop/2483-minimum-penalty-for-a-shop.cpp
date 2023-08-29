class Solution {
public:
    int bestClosingTime(string customers) {
        vector<int> pn; // prefix no count
        vector<int> sy(customers.size()); // suffix yes count
        
        int countN = 0;
        for(int i = 0;i<customers.size();i++){
            pn.push_back(countN);
            //cout<<countN <<" ";
            if(customers[i] == 'N'){
                countN++;
            }
        }
        cout<<"\n";
        int countY = 0;
        for(int i = customers.size()-1;i>=0;i--){
            sy[i] = countY;
            if(customers[i] =='Y'){
                countY++;
            }
        }
        
        //finding answer
        
        int ans = INT_MAX;
        int ansPen = INT_MAX;
        int penalty = 0;
        for(int i = 0;i<customers.size();i++){
            //Try closing at ith hour
            penalty = 0;
            if(customers[i] == 'Y'){
                // lost this customer
                penalty++;
            }
            //all customers after i are also lost
            penalty += sy[i];
            // all open hours before i with no customers adds in penalty
            penalty += pn[i];
            if(penalty < ansPen){
                ansPen = penalty;
                ans = i;
            }
        }
        penalty=0;
        int lastN=0;
        if(customers[customers.size()-1] == 'N'){
            lastN++;
        }
        lastN += pn[customers.size()-1];
        penalty += lastN;
        if(penalty < ansPen){
            ans = customers.size();
        }
        return ans;
    }
};