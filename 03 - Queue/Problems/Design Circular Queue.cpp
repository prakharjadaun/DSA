#include<vector>
using namespace std;

class MyCircularDeque {
public:
    vector<int> deq;
    int cap;
    MyCircularDeque(int k) {
        cap = k;
    }

    bool insertFront(int value) 
    {
        if(deq.size()==cap)
            return false;
        
        deq.insert(deq.begin(),value);
        return true;
    }
    
    bool insertLast(int value) 
    {
        if(deq.size()==cap)    
            return false;
        
        deq.push_back(value);
        return true;
    }
    
    bool deleteFront() 
    {
        if(deq.size()==0)    
            return false;
        
        deq.erase(deq.begin());
        return true;
    }
    
    bool deleteLast() 
    {
        if(deq.size()==0)    
            return false;
        deq.pop_back();
        return true;
    }
    
    int getFront() 
    {
        if(deq.size()==0)    
            return -1;
        return deq[0];
    }
    
    int getRear() 
    {
        if(deq.size()==0)    
            return -1;
        return deq[deq.size()-1];
    }
    
    bool isEmpty() 
    {
        return deq.empty();    
    }
    
    bool isFull() 
    {
        if(deq.size()==cap)    
            return true;
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */