class unionFind{
    vector<int>  group;
    vector<int>  rank;
    int comp;
public:
    unionFind(int size){
        comp = size;
        for(int i=0;i<=size;i++){
            group.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int node) {
        if(group[node] != node)
            group[node] = find(group[node]);
        return group[node];
    }

    bool join(int node1, int node2){
        int rep1 = find(node1);
        int rep2 = find(node2);
        if(rep1==rep2)
            return 0;
        else if(rank[rep1]>rank[rep2]){
            group[rep2]=rep1;
        }
        else if(rank[rep1]<rank[rep2]){
            group[rep1]=rep2;
        }
        else{
            group[rep2]=rep1;
            rank[rep1]++;
        }
        comp--;
        return 1;
    }

    bool areConnected(){
    if(comp==1)
        return true;
    return false;
    }
};


class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end());

        int used =0;
        unionFind alice(n);
        unionFind bob(n);
        for(auto elem:edges)
        {
            int type = elem[0];
            if(type == 3){
                used += (alice.join(elem[1], elem[2])|
                         bob.join(elem[1], elem[2]) );
            }
        }
        for(auto elem:edges)
        {
            int type = elem[0];
            if(type ==2){
                used += bob.join(elem[1], elem[2]);
            }
            else if(type ==1){
                used += alice.join(elem[1], elem[2]);
            }
        }
        if(alice.areConnected() && bob.areConnected()){
            return edges.size()-used;

        }
        return -1;
    }
};