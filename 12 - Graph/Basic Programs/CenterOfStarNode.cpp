#include<vector>
using namespace std;
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) 
    {
        int v = edges.size();
        vector<int> indeg(v+1,0);
        for(int i=0;i<v;i++)
        {
            indeg[edges[i][0]-1]++;
            indeg[edges[i][1]-1]++;
        }    

        for(int i=0;i<indeg.size();i++)
            if(indeg[i] == v)
                return i+1;
        return -1;
    }
};