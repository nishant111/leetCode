class Solution {
public:
    int find(string word, char ch){
        for(int i = 0;i<word.size();i++){
            char elem = word[i];
            if(elem == ch){
                return i;
            }
        }
        return -1;
    }
    
    string reverse(string word, int start, int end){
        while(start<=end){
            char tmp = word[start];
            word[start] = word[end];
            word[end] = tmp;
            start++;
            end--;
        }
        return word;
    }
    string reversePrefix(string word, char ch) {
        int start = 0;
        int end = find(word, ch);
        if(end == -1) return word;
        return reverse(word, start, end);
    }
};