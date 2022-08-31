#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//next Greater function to print the next greater element of the elements in the array
void NextGreater(int v[], int n)
{
    stack<int> s;
    //pushing the first element into the stack
    s.push(v[0]);

    for(int i=1;i<n;i++)
    {
        if(s.empty())
        {
            s.push(v[i]);
            continue;
        }

        while(!s.empty() && s.top()<v[i])
        {
            cout<<s.top()<<" : "<<v[i]<<endl;
            s.pop();
        } 
        s.push(v[i]);
    }

    while(!s.empty())
    {
        cout<<s.top()<<" : "<<-1<<endl;
        s.pop();
    }
}
int main()
{
    //creating a array of integer type
    int v[] = {22,44,12,14};
    int n = sizeof(v)/sizeof(v[0]);
    //calling the function NextGreater to print the next greater elements of the elements of the array and print -1 if there is not greater element present in the array
    NextGreater(v,n);

    return 0;
}