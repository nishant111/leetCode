class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(auto el:details){
            char age1 = el[11];
            char age2 = el[12];
            int age = int(age1-'0') * 10 + (age2-'0');
            if(age>60)
                ans++;
        }
        return ans;
    }
};