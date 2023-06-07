#include<iostream>
using namespace std;

//time complexity: O(3^n) (because of three recursive function calls) (The time complexity of the above solution is exponential, a close upper bound is O(3n). From each state 3, a recursive function is called. So the upper bound for n states is O(3n).)
//space complexity: O(1) (no extra space is required)
int countSteps(int dist)
{
    //if dist is less than 0, then return 0 (no solution exists)
    if(dist<0)
        return 0;
    //if dist is 0, that is you have reached the place: return 1
    if(dist==0)
        return 1;
    
    //you have three options, 1 step, 2 steps or 3 steps 
    // we can assume that you have three positions to reach the distance 
    //1. i-1
    //2. i-2
    //3. i-3
    //therefore, we make three recursive function calls 
    return countSteps(dist-1) + countSteps(dist-2) + countSteps(dist-3);
}

int main()
{
    int n = 4;
    cout<<countSteps(n)<<endl;
}