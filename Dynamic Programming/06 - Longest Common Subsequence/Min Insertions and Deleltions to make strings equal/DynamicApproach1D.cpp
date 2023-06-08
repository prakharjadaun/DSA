#include<iostream>
#include<vector>
using namespace std;

//time complexity:O(m*n)
//space complexity: O(n)
//function to find the length of longest common subsequence using space optimised approach
int lcs(string a, string b, int m, int n)
{
    //create a vector of n+1 size and fill it with 0s
    vector<int> dp(n+1,0);

    //iterate like a matrix 
    for(int i=1;i<=m;i++)
    {
        //take a prev variable to store the current dp[j] value
        int prev = 0;
        for(int j=1;j<=n;j++)
        {
            //storing the dp[j] variable
            int temp = dp[j];

            //if the elements are same at that iteration, then add 1 to the prev element
            if(a[i-1] == b[j-1])
                dp[j] = 1 + prev;
            else
            //else find the max of dp[j] and dp[j-1]
                dp[j] = max(dp[j], dp[j-1]);

            //updating the prev value
            prev = temp;
        }
    }
    //return the dp[n] element, which will give the length of LCS
    return dp[n];
}

void print(string a, string b, int m, int n)
{
    int l = lcs(a,b,m,n);
    cout<<l<<endl;
    cout<<"Minimum deletions: "<<(m-l)<<endl;
    cout<<"Minimum insertions: "<<(n-l)<<endl;
}

int main()
{
    string a = "heap";
    string b = "pea";
    int m = a.size();
    int n = b.size();

    print(a,b,m,n);
}