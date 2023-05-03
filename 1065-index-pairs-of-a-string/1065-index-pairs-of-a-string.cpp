class Solution {
public:
    class trie{
        public:
            vector<trie*> child;
            bool end;
            trie(){
                child.resize(26);
                end = false;
            }
            void insert(string a, trie* root){
                trie* iter=root;
                for(auto elem:a){
                    if(iter->child[elem-'a']!=NULL){
                        iter = iter->child[elem-'a'];
                    }
                    else{
                        iter->child[elem-'a']=new trie();
                        iter = iter->child[elem-'a'];
                    }
                }
                iter->end = true;
            }

    };
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        trie* root = new trie();
        vector<vector<int>> ans;
        for(auto elem:words){
            root->insert(elem, root);
        }
        for(int i = 0;i<text.size();i++){
            trie* tmpRoot = root;
            int j = i;
            for(;tmpRoot && j<text.size();j++){
                if(tmpRoot->end == true){
                        ans.push_back({i,j-1});
                }
                if(tmpRoot->child[text[j]-'a'] != NULL){
                    tmpRoot = tmpRoot->child[text[j]-'a'];
                }
                else{
                    break;
                }
            }
            if(j==text.size() && (tmpRoot->end == true)){
                    ans.push_back({i,j-1});
                }
        }
        return ans;
        
    }
};