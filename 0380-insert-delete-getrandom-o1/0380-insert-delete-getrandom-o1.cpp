class RandomizedSet {
public:
    vector<int> v;
    unordered_map<int, int> st;
    RandomizedSet() {
        //unordered_set<int> st;
    }
    
    bool insert(int val) {
        // return true if not present , false otherwise
        bool ret=false;
        if(st.find(val)==st.end()){
            st[val]=v.size();
            v.push_back(val);
            return true;
        }
        else
            return false;
    }
    
    bool remove(int val) {
        // return true if item was present, false otherwise
         if(st.find(val)!=st.end()){
            v[st[val]]=v.back();
            st[v[st[val]]] = st[val];
            v.pop_back();
            st.erase(val);
             
            return true;
        }
        else
            return false;
    }
    
    int getRandom() {
        // return element randomly, at equal probability
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */