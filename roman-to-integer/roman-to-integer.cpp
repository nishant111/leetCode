class Solution {
public:
    unordered_map<char, int> m = {
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000}
    };
    int romanToInt(string s) {
        int curr = 0;
        int last = -1;
        for(int i = s.size()-1;i>=0;i--){
            if(m[s[i]]>=last){
                curr+=m[s[i]];
            }
            else{
                curr-=m[s[i]];
            }
            last = m[s[i]];
        }
        return curr;
    }
};