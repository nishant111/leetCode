class Solution {
public:
    long long minimumSteps(string s) {
        int white = 0;
        int curr = 0;
        long long count = 0;
        while(curr < s.size() ){
            if( s[curr] == '0'){
                count += curr-white;
                white++;
            }
            curr++;
        }
        return count;
    }
};