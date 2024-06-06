class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> freq;
        if(hand.size() % groupSize != 0) return false;
        for( auto elem:hand ){
            freq[elem]++;
        }
        
        int smallest ;
        
        while(freq.size()>0){
            
            smallest = freq.begin()->first;
            int curr = smallest;
            while(curr < smallest + groupSize){
                if(freq.find(curr)==freq.end()) return false;
                freq[curr]--;
                if(freq[curr] == 0) freq.erase(curr);
                curr++;
            }
        }
        return true;
    }
};