#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int countPoints(string rings) {
        unordered_map<int,unordered_set<char>> hashmap;
        for(int i=0;i<rings.size();i+=2)
        {
            hashmap[rings[i+1]-'0'].insert(rings[i]);
        }

        int count = 0;
        for(auto temp : hashmap)
        {
            if(temp.second.size()==3)
                count++;
        }
        return count;
    }
};