#include<vector>
#include<unordered_map>
#include<sstream>
using namespace std;
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) 
    {
        unordered_map<string,int> hashmap;
        for(int i=0;i<cpdomains.size();i++)
        {
            stringstream s(cpdomains[i]);
            string count, url;
            s>>count;
            s>>url;

            hashmap[url]+= stoi(count);
            for(int i=0;i<url.size();i++)
            {
                if(url[i]=='.')
                    hashmap[url.substr(i+1)] += stoi(count);
            }
        }

        vector<string> res;
        string str;
        for(auto temp : hashmap)
        {
            str = to_string(temp.second) + " " + temp.first;
            res.push_back(str);
        }
        return res;
    }
};