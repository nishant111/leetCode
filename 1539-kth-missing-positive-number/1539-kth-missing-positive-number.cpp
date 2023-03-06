class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int counting =1;
        int i = 0;
        int missingSeq = 0;
        while(i<arr.size() ) {
            if(counting == arr[i])
            {
                cout <<"found " << counting <<" Go ahead\n";
                i++;
                counting++;
            }
            else if(counting !=arr[i]) {
                
                missingSeq++;
                cout <<"Didnt find " << counting <<" stay here\n";
                cout << "****Missing seq is" <<missingSeq<<"******\n";
                if(missingSeq == k)
                    return counting;
                counting++;
            }
            
        }
        return counting + k-1 - missingSeq;
    }
};