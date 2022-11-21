#include<bits/stdc++.h>
using namespace std;
int main()
{
    list<int> l1,l2;
    l1.push_back(5);
    l1.push_back(0);
    l1.push_back(4);

    l2.push_back(1);
    l2.push_back(4);
    l2.push_back(7);
    l2.push_back(9);

    int temp1=0, temp2=0;
    list<int>::iterator p = l1.begin();
    list<int>::iterator q = l2.begin();

    while(p!=l1.end())
    {
        temp1 = temp1 + (*p);
        p++;
        temp1 = temp1*10;
    }

    temp1 = temp1/10;

    while(q!=l2.end())
    {
        temp2 = temp2 + (*q);
        q++;
        temp2 = temp2*10;
    }
    temp2 = temp2/10;

    cout<<temp1+temp2<<endl;
}