#include <iostream>
#include <unordered_set>
using namespace std;

//function to return the size of the union of two arrays
int doUnion(int a[], int n, int b[], int m)
{
    //using the unordered_set because it contains the unique elements only and can be used to find the union of both the arrays
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(a[i]);
    }

    //inserting the distinct elements of the array b in set
    for (int i = 0; i < m; i++)
    {
        s.insert(b[i]);
    }

    //returning the size of the set
    return s.size();
}

int main()
{
    //initializing the two arrays
    int a[] = {2,1,4,5,2,4,6};
    int b[] = {9,5,3,6,2,7,3};

    //getting the size of both the arrays
    int n = sizeof(a)/sizeof(a[0]);
    int m = sizeof(b)/sizeof(b[0]);

    //printing the size of the union of both the arrays
    cout<<doUnion(a,n,b,m)<<endl;
}