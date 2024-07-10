class Solution {
public:
    int minOperations(vector<string>& logs) {
        int curr = 0;
        for(int i = 0;i<logs.size();i++){
            if(logs[i] == "../" && curr>0){
                curr--;   
            }
            else if(logs[i] == "./"){
                //stay here
                continue;
            }
            else if(logs[i] != "../" && logs[i] != "./"  ){
                curr++;
            }
        }
        return curr;
    }
};