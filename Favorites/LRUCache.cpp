#include<list>
#include<unordered_map>
using namespace std;
class LRUCache {
    //variable to store the capacity
    int cap;
    //list to store key:val pair passed to the function
    list<pair<int,int>> li;
    //unordered map to store the iterator against the key of the linked list
    unordered_map<int,list<pair<int,int>>::iterator> um;

public:
    LRUCache(int capacity)
    {
        //assigning the values and clearing the containers
        cap = capacity;
        li.clear();
        um.clear();
    }
    
    //function to get the key
    int get(int key) 
    {
        //if key do not exists in map, then it also not present in linked list
        if(um.find(key)==um.end())
            return -1;

        //if it is present, place that node to the beginning of the linked list
        //splice: [iterator position, list& x, iterator i]
        //iterator position: destionation where the iterator has to be placed
        //list & x: refers to the list from where the element will be taken
        //iterator i: iterator to be moved 
        li.splice(li.begin(),li,um[key]);

        //returning the value stored in that iterator
        return um[key]->second;    
    }
    
    void put(int key, int value) 
    {
        //if this key is already present in linked list, update the value
        if(this->get(key)!=-1)
        {
            //when we call get function it will already splice that node to the front
            um[key]->second = value;
            return;
        }    

        //if the list has reached the capacity
        if(um.size()==cap)
        {
            //get the key of the last element in the linked list
            int delkey = li.back().first;
            //remove the last element
            li.pop_back();
            //remove that element's key from the map
            um.erase(delkey);
        }

        //place the new key:val pair to the beginning 
        li.emplace_front(key,value);
        //place that key:val pair in map with their iterator
        um[key] = li.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */