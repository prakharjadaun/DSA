#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        //creating unordered_set to store the words
        unordered_set<string> hashset(wordList.begin(),wordList.end());
        //queue to perform BFS
        queue<pair<string,int>> q;
        //push the begin word with step = 1
        q.push({beginWord,1});
        //and erase the begin word from the set if exists
        hashset.erase(beginWord);

        while(!q.empty())
        {
            auto [word,steps] = q.front();
            q.pop();
            //if word present in queue is equal to endword, return the steps
            if(word == endWord)
                return steps;

            //iterate to each character of the word
            for(int i=0;i<word.size();i++)
            {
                char orig = word[i];
                //replace each character instead of orig
                for(char ch ='a';ch<='z';ch++)
                {
                    word[i] = ch;
                    //if the new word exists in set, erase it and add it to queue with step + 1
                    if(hashset.find(word)!=hashset.end())
                    {
                        q.push({word,steps+1});
                        hashset.erase(word);
                    }
                }
                //restore the character 
                word[i] = orig;
            }
        }
        return 0;
    }
};