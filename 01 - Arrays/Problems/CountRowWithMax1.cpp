#include<vector>
using namespace std;
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int row = -1;
	    int countOnes = 0,max_ones=0;
	    for(int i=0;i<n;i++)
	    {
	        countOnes = 0;
	        for(int j=0;j<m;j++)
	        {
	            if(arr[i][j] == 1)
	                countOnes++;
	        }
	        
	        if(countOnes > max_ones)
	        {
	            max_ones = countOnes;
	            row = i;
	        }
	    }
	    return row;
	}

};