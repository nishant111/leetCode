class Solution {
public:
    int makeInt(string subs)
    {
        
        int sum = 0;
        for(int i = 0;i<subs.size();i++)
        {
            int val = subs[i] - '0';
            sum =sum*2 +  val;
        }
        return sum;
    }
    bool hasAllCodes(string s, int k) {
        if(k>s.size()) return false;
        int winSize = k;
        unordered_set <int> st;
        int start = 0;
        int end = k-1;
        
        for(int i = 0;i<=(s.size()-k);i++)
        {
            int end = i+(k-1) ;
            st.insert({makeInt(s.substr(i, end - i +1))});
        }
        
        
        
        if(st.size() == pow(2,k))
            return true;
        else
            return false;
    }
};