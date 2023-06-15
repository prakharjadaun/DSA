#include<vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) 
    {
        //getting the size of the number of citations the user have performed 
        int n = citations.size();
        //initialize an array having size n + 1 and filled with zeros
        vector<int> a(n+1,0);

        //ideology: we will iterate through each element of the citations array
        //let's say 
        //[3, 0, 6, 1, 5]
        //[0, 0, 0, 0, 0, 0]   -> a

        //if that element of citations have index under the size of citations then we increment that index, otherwise increment the index a[n] (here we will store the count of papers having citations greater than the size of citations array)
        for(int i: citations)
        {
            if(i>=n)
            {
                a[n]++;
            }
            else
            {
                a[i]++;
            }
        }

        //then we start from the last element and keep adding the variable count and when count >= i, we return that index
        int count = 0;
        for(int i=n;i>=0;i--)
        {
            count+= a[i];
            if(count >= i)
                return i;
            
        }
        return 0;
    }
};