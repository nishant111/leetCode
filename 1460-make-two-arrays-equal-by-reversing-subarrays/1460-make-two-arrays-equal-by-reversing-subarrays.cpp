class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> a;
        for(auto el:arr){
            a[el]++;
        }
        for(auto el:target){
            if(a.find(el)==a.end()){
                return false;
            }
            else{
                if(a[el] == 1){
                    a.erase(el);
                }
                else{
                    a[el]--;
                }
                
            }
        }
        if(a.size()==0)
            return true;
        return false;
    }
};