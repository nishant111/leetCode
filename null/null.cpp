class Trie {
public:
    Trie* child[26];
    bool end;
    Trie() {
        for(int i=0;i<26;i++)
        {
            child[i] = NULL;
        }
        end = false;
    }
    
    void insert(string word) {
        Trie *curr = this;
        for(auto elem:word) {
            if(curr->child[elem-'a'] == NULL){
                curr->child[elem-'a'] = new Trie();
                curr=curr->child[elem-'a'];
            }
            else {
                curr = curr->child[elem-'a'];
            }
        }
        curr->end = true;
    }
    
    bool search(string word) {
        Trie *curr = this;
        for(auto elem:word) {
            if(curr->child[elem -'a'] == NULL) {
                return false;
            }
            else {
                curr = curr->child[elem-'a'];
            }
        }
        return curr->end;
    }
    
    bool startsWith(string prefix) {
        Trie *curr = this;
        for(auto elem:prefix) {
            if(curr->child[elem -'a'] == NULL) {
                return false;
            }
            else {
                curr = curr->child[elem-'a'];
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */