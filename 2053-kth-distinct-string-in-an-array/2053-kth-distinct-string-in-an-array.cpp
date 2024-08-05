class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> dist;
        for(auto el:arr){
                dist[el]++;
        }
        int count = 0;
        for(auto el:arr){
            if(dist.find(el)!=dist.end() && dist[el] == 1){
                count++;
            }
            if(count == k){
                return el;
            }
        }
        return "";
    }
};