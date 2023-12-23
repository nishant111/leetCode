class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string> st;
        
        pair<int, int> start = {0,0};
        st.insert("0_0");
        for(auto elem:path){
            if(elem=='N'){
                start.first+=1;
            }
            else if(elem=='S'){
                start.first-=1;
            }
            else if(elem=='E'){
                start.second+=1;
            }
            else if(elem=='W'){
                start.second-=1;
            }
            string curr = to_string(start.first) + '_' + to_string(start.second);
            if(st.find(curr)==st.end())
                st.insert(curr);
            else
                return true;
        }
        return false;
    }
};