class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> st;
        
        for(auto el:dictionary){
            st.insert(el);
        }
        int curr = 0;
        string ans = "";
        while(curr<sentence.size()){
            string currWord = "";
            while(curr<sentence.size() && sentence[curr]!=' '){
                currWord += sentence[curr++];
                if(st.find(currWord)!=st.end()){
                    while(curr<sentence.size() && sentence[curr]!=' ')
                        curr++;
                    break;
                }
            }
            if(curr<sentence.size())
                ans += currWord + sentence[curr++];
            else
                ans += currWord;
        }
         return ans;  
    }
};