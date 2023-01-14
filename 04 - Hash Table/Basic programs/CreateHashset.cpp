#include<iostream>
class MyHashSet {
    // as range of values were 0-10^6
    int arr[1000001];
public:
    
    MyHashSet() 
    {
            
    }
    
    void add(int key) 
    {
        arr[key]=1;
    }
    
    void remove(int key) 
    {
        arr[key]=0;    
    }
    
    bool contains(int key) 
    {
        if(arr[key]==1)
        return true;
        else 
        return false;    
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */