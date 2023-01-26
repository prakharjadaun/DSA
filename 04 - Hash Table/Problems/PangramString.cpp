#include<unordered_set>
#include<string>
using namespace std;
class Solution {
public:
    bool checkIfPangram(string sentence) 
    {
        unordered_set<char> hashset;
        for(int i=0;i<sentence.size();i++)
        hashset.insert(sentence[i]);

        if(hashset.size()==26)
        return true;
        return false;
    }
};