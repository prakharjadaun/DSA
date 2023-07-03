#include<vector>
using namespace std;

class Solution{
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr,int N, int P)
    { 
        // code here
        for(int i=0;i<N;i++)
        {
            //if element is greater than N assign 0
            if(arr[i]>N)
                arr[i]=0;
        }
        
        for(int i=0;i<N;i++)
        {
            //if that index is greater than 0 after N+1, then add N+1 to that modulo -1 index
            if(arr[i]%(N+1)>0)
                arr[(arr[i] %(N+1))-1] += (N+1);
        }
        
        //divide all elements by N+1
        for(int i=0;i<N;i++)
        {
            arr[i] /= (N+1);
        }
    }
};