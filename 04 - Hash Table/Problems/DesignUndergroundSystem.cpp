#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
class UndergroundSystem {
public:
    map<int,pair<string,int>> hashmap;
    map<pair<string,string>,vector<int>> stations;
    UndergroundSystem() 
    {
        
    }
    
    void checkIn(int id, string stationName, int t) 
    {
        hashmap[id] = {stationName,t};    
    }
    
    void checkOut(int id, string stationName, int t) 
    {
        stations[{hashmap[id].first,stationName}].push_back(t - hashmap[id].second);  
    }
    
    double getAverageTime(string startStation, string endStation) {
        return (double)accumulate(stations[{startStation,endStation}].begin(),stations[{startStation,endStation}].end(),0) / stations[{startStation,endStation}].size();
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */