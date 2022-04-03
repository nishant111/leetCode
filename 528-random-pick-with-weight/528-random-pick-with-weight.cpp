class Solution {
public:
    vector<int> pickArray;
    //vector<int> origArray;
    int sum = 0;
    Solution(vector<int>& w) {
        //origArray = w;
        for(int i = 0;i<w.size();i++)
        {
            sum += w[i];
            pickArray.push_back(sum);
        }
    }
    
    int pickIndex() {
        int tmp = (rand() % sum);
        for(int i = 0;i<pickArray.size();i++)
        {
            if(tmp<pickArray[i])
                return i;
        }
        return pickArray.size()-1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */