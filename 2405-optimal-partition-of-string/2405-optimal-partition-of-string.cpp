class Solution {
public:
    int partitionString(string s) {
        int l = 0;
        int r = 0;
        int count = 1;
        unordered_set<char> seen;
        while(r<s.size()) {
            if(seen.find(s[r])==seen.end()) {
                seen.insert(s[r++]);
            }
            else if(seen.find(s[r])!=seen.end()) {
                count++;
                seen.clear();
                seen.insert(s[r++]);
            }
        }
        return count;
    }
};