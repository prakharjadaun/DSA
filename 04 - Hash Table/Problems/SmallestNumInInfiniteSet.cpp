#include<set>
using namespace std;
class SmallestInfiniteSet {
public:
    set<int> popped;
    SmallestInfiniteSet() 
    {
        
    }
    
    int popSmallest() 
    {
        if(popped.size()==0)
        {
            popped.insert(1);
            return 1;
        }

        int i = 1;
        for(auto temp : popped)
        {
            if(i==temp)
            {
                i++;
            }
            else
            {
                break;
            }
        }
        popped.insert(i);
        return i;
    }
    
    void addBack(int num) 
    {
        if(popped.find(num)!=popped.end())
            popped.erase(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */