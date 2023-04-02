class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int p =potions.size();
        sort(potions.begin(), potions.end());
        vector<int> ans;
        for(auto elem:spells) {
            //double targ = (double)success/(double)elem;
            int l = 0;
            int r = p-1;
            //cout <<"targ is" << targ<<"**";
            while(l<=r) {
                int mid = l + (r-l)/2;
                //cout <<" mid is:" <<mid<<"** ";
                long product = long(elem) * potions[mid];
                if(product < success) {
                    l=mid+1;
                }
                else if(product >= success) {
                    r = mid -1;
                }
            }
            //cout <<" correct pos is :"<<l<<"\n";
            ans.push_back(p-l);
        }
        return ans;
    }
};