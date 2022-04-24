typedef struct item_{
  
    string startStation;
    int time;
}item;

class UndergroundSystem {
public:
    unordered_map <string, vector<int>> timeMap;
    unordered_map<int, item> idMap;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        item checkIn;
        checkIn.startStation = stationName;
        checkIn.time = t;
        idMap.insert({id, checkIn});
    }
    
    void checkOut(int id, string stationName, int t) {
        if(idMap.find(id)!= idMap.end())
        {
            int diff = t - idMap[id].time;
            string res =  idMap[id].startStation + '-' + stationName;
            timeMap[res].push_back(diff);
            idMap.erase(id);
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        string res = startStation + '-' + endStation;
        
        if(timeMap.find(res)!=timeMap.end())
        {
            //found journeys
            double ans=0;
            for(int i = 0;i<timeMap[res].size();i++)
            {
                ans += timeMap[res][i];
            }
            return ( ans/(double)timeMap[res].size() );
        }
        return -1;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */