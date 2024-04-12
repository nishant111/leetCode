class Solution {
public:
    void printArray(vector<int> arr)
    {
        for(auto elem:arr)
        {
            cout << elem << " ";
        }
        cout <<"\n";
    }
    void MTOL(vector<int> &h, vector<int> & mtol)
    {
        mtol[0] = 0;
        int maxi = h[0];
        for(int i = 1;i<h.size();i++)
        {
            mtol[i]=maxi;
            maxi = max(h[i], maxi);
        }
        //printArray(mtol);
    }
    void MTOR(vector<int> &h, vector<int> & mtor)
    {
        mtor[h.size()-1] = 0;
        int maxi = h[h.size()-1];
        for(int i = h.size()-2;i>=0;i--)
        {
            mtor[i]=maxi;
            maxi = max(h[i], maxi);
        }
        //printArray(mtor);
    }
    int trap(vector<int>& height) {
        vector<int> mtol (height.size(), 0);
        vector<int> mtor (height.size(), 0);
        MTOL(height, mtol);
        MTOR(height, mtor);
        int ans = 0;

        for(int i = 0;i<height.size();i++){
            int toi = min(mtol[i], mtor[i]);
            cout << "tower of intereset for "<<i<<" is" << toi<<"\n";
            if(toi <= height[i] || toi == 0) continue;
            else
                ans += toi - height[i];
        }
        return ans;
    }
};