#include<bits/stdc++.h>
using namespace std;
void display(list<int> l)
{
    for(auto temp:l)
    {
        cout<<temp<<" ";
    }
    cout<<endl;
}

void mergelist(list<int> l1,list<int> l2)
{
    list<int> l3;
    list<int>::iterator p = l1.begin(), q = l2.begin();
    while(p!=l1.end() && q!=l2.end())
    {
        if(*p < *q)
        {
            l3.push_back(*p);
            p++;
        }
        else if(*p > *q)
        {
            l3.push_back(*q);
            q++;
        }
        else if(*p==*q)
        {
            l3.push_back(*p);
            l3.push_back(*q);
            p++;
            q++;
        }
    }

    while(p != l1.end())
    {
        l3.push_back(*p);
        p++;
    }

    while(q != l2.end())
    {
        l3.push_back(*q);
        q++;
    }

    display(l3);
}
int main()
{
    list<int> l1,l2;
    l1.push_back(12);
    l1.push_back(14);
    l1.push_back(91);
    l1.push_back(16);
    l1.push_back(1);
    l1.sort();  //sort function

    l2.push_back(0);
    l2.push_back(13);
    l2.push_back(17);
    l2.sort();  //sort function 
    //n logn is time complexity 

    display(l1);
    display(l2);

    mergelist(l1,l2);
    
    return 0;
}