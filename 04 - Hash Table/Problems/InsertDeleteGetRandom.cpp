#include<unordered_map>
#include<vector>

using namespace std;
class RandomizedSet {
    unordered_map<int,int> hashmap;
    vector<int> nums;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) 
    {
        if(hashmap.find(val)!=hashmap.end())
            return false;

        nums.emplace_back(val);
        hashmap[val] = nums.size()-1;
        return true;    
    }
    
    bool remove(int val) 
    {
        if(hashmap.find(val)==hashmap.end())
            return false;

        int last = nums.back();
        hashmap[last] = hashmap[val];
        nums[hashmap[val]] = last;

        nums.pop_back();
        hashmap.erase(val);
        return true;
        
    }
    
    int getRandom() 
    {
        return nums[rand() % nums.size()];    
    }
};
