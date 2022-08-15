#include<bits/stdc++.h>
using namespace std;
void display(priority_queue<int,vector<int>,greater<int>> q)
{
    priority_queue<int, vector<int>, greater<int>> temp = q;
    while(!temp.empty())
    {
        cout<<temp.top()<<" ";
        temp.pop();
    }
    cout<<endl;
}
int main()
{
    priority_queue<int,vector<int>,greater<int>> q;
    int n,temp;
    cout<<"Enter n : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        q.push(temp);
    }
    //displaying the priority queue
    display(q);

    cout<<"Top element : "<<q.top()<<endl;
    cout<<"Size of the priority queue : "<<q.size()<<endl;
    return 0;

}