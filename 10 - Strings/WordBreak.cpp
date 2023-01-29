#include <unordered_set>
#include<iostream>
#include <vector>
#include <string>
#include<cstring>
using namespace std;
class Solution
{
public:
    int wordBreak(string A, vector<string> &B)
    {
        // code here
        unordered_set<string> hashset;
        string str = "";
        for (auto temp : B)
        {
            hashset.insert(temp);
            // cout<<temp<<endl;
        }

        int j = 0;
        for (int i = 0; i < A.size(); i++)
        {
            if (hashset.find(A.substr(j, i-j+1)) != hashset.end())
            {

                // cout<<"$$"<<i<<" : "<<j<<endl;

                string n = A.substr(j, i-j);
                cout<<n<<endl;;
                str = str + n;
                j =  i-j+1;
            }
        }
        cout<<str<<endl;
        if (str.size() == A.size())
            return 1;
        return 0;
    }
};

int main()
{
    string A = "ilike";
    vector<string> B = {"i", "like", "sam",
                        "sung", "samsung", "mobile",
                        "ice", "cream", "icecream",
                        "man", "go", "mango"};

    Solution sol;
    // cout<<A.substr(1,4)<<endl;
    cout<<sol.wordBreak(A,B)<<endl;
}