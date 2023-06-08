#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;
int dp[1000][1000];

int lcs(string a, string b, int i, int j)
{
    //assigning the 0th row and column 0
    if(i==0 || j==0)
        return 0;
    //if the value is not -1, we return that value
    if(dp[i][j]!=-1)
    {
        cout<<dp[i][j]<<endl;
        return dp[i][j];
    }
    //if both the string values are equal, then we return 1+value at upper left diagonal place
    else if(a[i-1] == b[j-1])
        return dp[i][j] = 1 + lcs(a,b,i-1,j-1);
    else 
    //if both the string values are not equal, then we return the max value of the upper row and left column place value
        return dp[i][j] = max(lcs(a,b,i-1,j),lcs(a,b,i,j-1));
}

//printing the minimum deletions and minimum insertions
void print( string a, string b, int i, int j)
{
    int l = lcs(a,b,i,j);
    cout<<l<<endl;
    cout<<"Minimum deletions: "<<(i-l)<<endl;
    cout<<"Minimum insertions: "<<(j-l)<<endl;
}   


int main()
{
    string a = "heap";
    string b = "pea";

    int m = a.size();
    int n = b.size();

    dp[m+1][n+1];

    //filling -1 in the matrix
    memset(dp,-1,sizeof(dp));

    print(a,b,m,n);
}