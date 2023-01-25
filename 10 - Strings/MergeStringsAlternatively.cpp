#include<string>
using namespace std;
class Solution {
public:
    string mergeAlternately(string word1, string word2) 
    {
        string merged="";
        int i=0,j=0,k=0;
        while(i<word1.size() && j<word2.size())
        {
            if(k%2==0)
            {
                merged+= word1[i];
                i++;
            }
            else
            {
                merged+= word2[j];
                j++;
            }
            k++;
        }    
        while(i<word1.size())
        {
            merged+= word1[i];
            i++;
        }
        while(j<word2.size())
        {
            merged+= word2[j];
            j++;
        }
        return merged;
    }
};