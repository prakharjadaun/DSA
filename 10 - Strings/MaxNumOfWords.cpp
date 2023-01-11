#include<vector>
#include<string>
#include<climits>
#include<sstream>
using namespace std;
class Solution {
public:
    int mostWordsFound(vector<string>& sentences) 
    {
        //definning the variables
        int max_fre = INT_MIN,temp = 0;
        string word;
        //iterating through the each sentences
        for(int i=0;i<sentences.size();i++)
        {
            //creating a stringstream object for each string 
            stringstream ss(sentences[i]);
            temp = 0;
            //counting the number of words in each sentence
            while(ss>>word)
            {
                temp++;
            }
            //comparing it with the maximum frequency
            if(temp > max_fre)
            {
                max_fre = temp;
            }
        }       
        //returning the maximum frequency
        return max_fre;
    }
};