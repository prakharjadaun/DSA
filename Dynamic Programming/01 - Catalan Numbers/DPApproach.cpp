#include<iostream>
#include<stdlib.h>
using namespace std;

//time complexity : O(n^2)
//space complexity : O(n)
unsigned long int catalanDP(int num)
{
    unsigned long int *cat = (unsigned long int *)malloc((num+1)*sizeof(unsigned long int));
    // unsigned long int cat[num+1];

    cat[0] = 1;
    if(num>=1)
    {
        cat[1] = 1;

        for(int i=2;i<=num;i++)
        {
            cat[i] = 0;
            for(int j=0;j<i;j++)
                cat[i] += (cat[j] * cat[i-j-1]);
        }
    }
    return cat[num];
}

int main()
{
    for(int i=0;i<10;i++)
        cout<<catalanDP(i)<<endl;
}