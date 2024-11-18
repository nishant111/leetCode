class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        bool neg = k < 0;
        if(neg)
            k = k*-1;
        int winsum = 0;
        int l;
        int r;
        if(k == 0){
            l=0;
            r=-1;
        }
        else if(!neg){
            l = (1)%code.size();
            r = (k)%code.size();
        }
        else{
            r = code.size()-1;
            l = code.size()-1 - (k-1);
        }
        for( int i = l;i<=r;i++){
            winsum += code[i];
        }
        vector<int> ans;
        for( int i = 0 ;i<code.size();i++){
            ans.push_back(winsum);
            winsum = winsum - code[l];
            l = (l+1)%code.size();
            r = (r+1)%code.size();
            winsum += code[r];
        }
        return ans;
        
    }
};