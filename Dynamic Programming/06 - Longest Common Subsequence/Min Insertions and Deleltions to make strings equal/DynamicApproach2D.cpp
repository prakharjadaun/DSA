#include<iostream>
using namespace std;

//time complexity: O(m*n)
//space complexity: O(m*n)
int lcs(string a, string b, int m, int n)
{
    int dp[m+1][n+1];
    //M
    for(int i=0;i<=m;i++)
    {   
        //N
        for(int j=0;j<=n;j++)
        {   
            //filling the 0th row and column with 0
            if(i==0 || j==0)
                dp[i][j]=0;
            //if the character in a and b are equal, then add 1 to the upper diagonal element
            else if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
            //if the characters in a and b are not equal then assign the max of the upper row and left column value
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    //return the mth row and nth col value stored in the matrix
    return dp[m][n];
}

//function to get the minimum insertions and deletions
void minInsertionsAndDeletions(string a, string b, int m, int n)
{
    //getting the length of longest common subsequence
    int l = lcs(a,b,m,n);
    //minimum deletions will be (m-l) because we want to delete the elements from the first string
    cout<<"Minimum deletions: "<<(m-l)<<endl;
    //minimum insertions will be (n-l) because we want to insert the elements into the second string
    cout<<"Minimum insertions: "<<(n-l)<<endl;
}
int main()
{
    //definning the two strings
    string a = "heap";
    string b = "pea";
    //storing their lengths
    int m = a.size();
    int n = b.size();
    //calling the function to get the desired result
    minInsertionsAndDeletions(a,b,m,n);
    return 0;
}