#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        //creating a vector for all 0-255 characters and assigning -1 to all the places (which represents their frequency)
        vector<int> hashset(256,-1);
        int maxLen = 0, start = -1;
        for(int i=0;i<s.size();i++)
        {
            //if that character is repeated then, we reassign the value of start (the index which is assign to that position)
            if(hashset[s[i]] > start)
                start = hashset[s[i]];
            //assigning the latest index to that character position in the vector
            hashset[s[i]] = i;
            //getting the maximum length of the substring 
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};