#include <bits/stdc++.h>
using namespace std;
struct item
{
    string name;
    int val;
};
int CountItems(item list1[], item list2[], int m, int n)
{
    int ans=0;
    unordered_map<string,int> um;
    for(int i=0;i<m;i++)
    {
        um[list1[i].name] = list1[i].val;
    }

    for(int i=0;i<n;i++)
    {
        if(um.find(list2[i].name)!=um.end() && um[list2[i].name]!=list2[i].val)
        {
            ans++;
        }
    }
    return ans;
}
int main()
{
    item list1[] = {{"apple", 60}, 
                    {"bread", 20}, 
                    {"wheat", 50}, 
                    {"oil", 30}};
    item list2[] = {{"milk", 20}, 
                    {"bread", 15}, 
                    {"wheat", 40}, 
                    {"apple", 60}};

    int m = sizeof(list1)/sizeof(list1[0]);
    int n = sizeof(list2)/sizeof(list2[0]);

    cout<<CountItems(list1,list2,m,n)<<endl;
}