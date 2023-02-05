#include<vector>
#include<string>
#include<numeric>
using namespace std;
class Solution {
public:
    int calPoints(vector<string>& operations) 
    {
        vector<int> vec;
        for(int i=0;i<operations.size();i++)
        {
            if(operations[i]=="+")
            {
                int temp = vec[vec.size()-1]+ vec[vec.size()-2];
                vec.push_back(temp);
            }
            else if(operations[i]=="D")
            {
                int temp = vec[vec.size()-1]*2;
                vec.push_back(temp);
            }
            else if(operations[i]=="C")
            {
                vec.pop_back();
            }
            else
            {
                int temp = stoi(operations[i]);
                vec.push_back(temp);
            }
        }
        return accumulate(vec.begin(),vec.end(),0);
    }
};