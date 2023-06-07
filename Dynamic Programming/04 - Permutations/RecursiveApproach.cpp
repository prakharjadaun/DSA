#include<iostream>
using namespace std;


//time complexity:O(N * N!) Note that there are N! permutations and it requires O(N) time to print a permutation.
//space complexity: O(R – L)
void permute(string str,int l, int r)
{
    //base case: if l is equal to r, then print the string
    if(l==r)
        cout<<str<<endl;
    else
    {
        //iterate from l to r
        //swap the l and ith element and make a recursive call again
        //after the recursive call, the swap again (basically fix the changes)
        for(int i=l;i<=r;i++)
        {
            swap(str[l],str[i]);

            permute(str,l+1,r);

            swap(str[l],str[i]);
        }
    }
}

int main()
{
    string str = "ABC";
    int l = 0, r = str.size()-1;

    permute(str,l,r);
}