class MyHashMap {
public:
    vector<int> mp;
    MyHashMap() {
        mp.resize(10, -1);
    }
    
    void put(int key, int value) {
        while(key>=mp.size()){
            mp.resize(mp.size()*2, -1);
        }
        mp[key] = value;
    }
    
    int get(int key) {
        if(key>=mp.size()) return -1;
        return mp[key];
    }
    
    void remove(int key) {
        if(key>=mp.size()) return;
        mp[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */