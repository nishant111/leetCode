class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        int i1 = 0;
        int i2 = 0;
        
        while(i1<version1.size() || i2<version2.size()){
            string v1 = "";
            string v2 = "";
            while(i1<version1.size() && version1[i1]!='.'){
                v1 = v1 + version1[i1++];
            }
            i1++;
            while(i2<version2.size() && version2[i2]!='.'){
                v2 = v2 + version2[i2++];
            }
            i2++;
            if(v1.size()==0)
                v1="0";
            if(v2.size()==0)
                v2="0";
            int one = stoi(v1);
            int two = stoi(v2);
            if(one<two) return -1;
            else if(one>two) return 1;
        }
        return 0;
    }
};