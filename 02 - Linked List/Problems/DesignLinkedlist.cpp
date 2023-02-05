#include<vector>
using namespace std;
class MyLinkedList {
public:
    vector<int> vec;
    MyLinkedList() {
        
    }
    
    int get(int index) 
    {
        if(index >= vec.size())
            return -1;
        return vec[index];    
    }
    
    void addAtHead(int val) 
    {
        vector<int> temp;
        temp.push_back(val);
        temp.insert(temp.end(),vec.begin(),vec.end());
        vec = temp;
        temp.clear();    
    }
    
    void addAtTail(int val) 
    {
        vec.push_back(val);    
    }
    
    void addAtIndex(int index, int val) 
    {
        if(index == vec.size())
            vec.push_back(val);
        else if(index < vec.size())
            vec.insert(vec.begin()+index,val);    
    }
    
    void deleteAtIndex(int index) 
    {
        if(index < vec.size())
            vec.erase(vec.begin()+index);
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */