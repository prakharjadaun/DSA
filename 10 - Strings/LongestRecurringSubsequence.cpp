#include<iostream>
#include<unordered_map>
#include<climits>
using namespace std;

unordered_map<string,int> hashmap;
void computeSubsequences(string input, string output)
{
    if(input.empty())
    {
        hashmap[output]++;
        // cout<<output<<endl;
    }
    else
    {
        computeSubsequences(input.substr(1),output + input[0]);
        computeSubsequences(input.substr(1),output);
    }
}


int main()
{
    string input = "axxzxy";
    string output = "";

    computeSubsequences(input,output);

    string ans;
    int min_len = 0;

    for(auto temp : hashmap)
    {
        if(temp.first.size() > min_len && temp.second>1)
        {
            ans = temp.first;
            min_len = temp.first.size();
        }
    }

    cout<<ans<<endl;

}