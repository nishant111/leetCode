class Trie {
private:
    char c;
    Trie *child['z'-'a'+1];
    bool end;
public:
    Trie *root;
    Trie() {
        root = (Trie *)calloc(1, sizeof(Trie));
        root -> c = '\0';
        end = false;
    }
    
    void insert(string word) {
        Trie *curr = root;
        for(int i = 0;word[i]!='\0';i++)
        {
            if(curr->child[word[i] - 'a'] == NULL)
            {
                // empty
                curr ->child[word[i] - 'a'] = (Trie*)calloc(1, sizeof(Trie));
                curr = curr->child[word[i] - 'a'];
                curr -> c = word[i];
            }
            else if(curr->child[word[i]-'a'] !=NULL)
            {    
                curr = curr->child[word[i]-'a'];
            }
        }
        curr -> end = true;
    }
    
    bool search(string word) {
        Trie *curr = root;
        for(int i = 0;word[i]!='\0';i++)
        {
            if(curr->child[word[i] - 'a'] == NULL)
            {
                return false;
            }
            else if(curr->child[word[i]-'a'] !=NULL)
            {    
                curr = curr->child[word[i]-'a'];
            }
        }
        if(curr -> end == true)
            return true;
        else
            return false;
    }
    
    bool startsWith(string prefix) {
       Trie *curr = root;
        for(int i = 0;prefix[i]!='\0';i++)
        {
            if(curr->child[prefix[i] - 'a'] == NULL)
            {
                return false;
            }
            else if(curr->child[prefix[i]-'a'] !=NULL)
            {    
                curr = curr->child[prefix[i]-'a'];
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