//{ Driver Code Starts
//Initial template for C++

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;  // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    
    //Function to find the nth catalan number.
    cpp_int findCatalan(int n) 
    {
        vector<cpp_int> res(n+1);
        
        res[0] = 1;
        if(n>=1)
        {
            res[1] = 1;
            
            for(int i=2;i<=n;i++)
            {
                res[i] = 0;
                for(int j=0;j<i;j++)
                    res[i] += (res[j] * res[i-j-1]);
            }
        }
        return res[n];
    }
};

//{ Driver Code Starts.

int main() 
{
    //taking count of testcases
	int t;
	cin>>t;
	while(t--) {
	    
	    //taking nth number
	    int n;
	    cin>>n;
	    Solution obj;
	    //calling function findCatalan function
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends