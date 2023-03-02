class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size()==1) return 1;
        int wi = 0;
        int count = 0;
        for(int i = 0;i<chars.size();i++){
            char curr = chars[i];
            count=1;
            while(i+1<chars.size() && chars[i] == chars[i+1]){
                i++;
                count++;
            }
            if(count > 1) {
                chars[wi++] = curr;
                if(count < 10)
                    chars[wi++] = count + '0';
                else {
                    vector<char> tmp;
                    while(count){
                        tmp.push_back(count%10 + '0');
                        count /= 10;
                    }
                    reverse(tmp.begin(), tmp.end());
                    for(auto elem:tmp){
                        chars[wi++] = elem;
                    }
                }
            }
            else if(count == 1){
                chars[wi++]=curr;
            }
        }
        chars.resize(wi);
        return wi;
    }
};