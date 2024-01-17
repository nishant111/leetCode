class Solution {
public:
    int freq[2001]={0};
    bool uniqueOccurrences(vector<int>& arr) {
        for(auto elem:arr){
            freq[elem+1000]++;
        }
        unordered_set<int> st;
        for(int i=0;i<2001;i++){
            if(freq[i]!=0){
                if(st.find(freq[i])!=st.end())
                    return false;
                else
                    st.insert(freq[i]);
            }
        }
        return true;
    }
};