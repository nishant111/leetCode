class SnapshotArray {
public:
    vector<int> arr;
    int curr_snap_id =0;
    vector<unordered_map <int, int>> mapArr;
    SnapshotArray(int length) {
        arr = vector<int> (length);
        mapArr = vector<unordered_map <int, int>>(length);
    }
    
    void set(int index, int val) {
        arr[index] = val;
        mapArr[index][curr_snap_id] = val;
    }
    
    int snap() {
        curr_snap_id++;
        return curr_snap_id-1;
    }
    
    int get(int index, int snap_id) {
        if(mapArr[index].find(snap_id) == mapArr[index].end())
        {
            if(snap_id == 0) return 0;
            return get(index, snap_id-1);
        }
        return mapArr[index][snap_id];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */