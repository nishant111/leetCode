class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry = 0;
        int i = num.size()-1;
        vector<int> ans;
        while(k>0 || i>= 0)
        {
            int sum = 0;
            if(k>0)
                sum += k%10;
            if(i>=0)
            {
                sum += num[i];
            }
            if(carry)
                sum += carry;
            
            ans.push_back(sum%10);
            carry = sum/10;
            k = k/10;
            i--;
        }
        if(carry)
            ans.push_back(carry);
        reverse(ans.begin(), ans.end());
        return ans;

    }
};