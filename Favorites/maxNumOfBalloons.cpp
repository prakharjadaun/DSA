#include<unordered_map>
#include<string>
using namespace std;
class Solution {
public:
    int maxNumberOfBalloons(string text) 
    {
        unordered_map<char,int> hashmap;
        for(char ch : text)
        {
            hashmap[ch]++;
        }

        return min(hashmap['b'],min(hashmap['a'],min(hashmap['l']/2,min(hashmap['o']/2,hashmap['n']))));
    }
};