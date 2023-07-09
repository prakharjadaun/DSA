#include<string>
#include<vector>
#include<queue>
using namespace std;
class Solution{
    public:
    string findOrder(string dict[], int N, int K) 
    {
        //code here
        string ans = "";
        vector<int> adj[K];
        //we will compare the string i with i+1, and when the elemnt do not match, it means that the character in str1 will appear before the character present in str2
        //based on this intuition we will form our adjacency list
        for(int i=0;i<N-1;i++)
        {
            string str1 = dict[i];
            string str2 = dict[i+1];
            int len = min(str1.size(),str2.size());
            for(int j=0;j<len;j++)
            {
                if(str1[j]!=str2[j]){
                    //subtracting 'a' to make them form 0,1,2
                    adj[str1[j]-'a'].push_back(str2[j]-'a');
                    break;
                }                    
            }
        }
        
        //computing the indegree 
        vector<int> indeg(K,0);
        for(int i=0;i<K;i++)
        {
            for(auto it: adj[i])
                indeg[it]++;
        }
        
        queue<int> q;
        //whose indegree is 0, placing them into the queue
        for(int i=0;i<K;i++)
            if(indeg[i]==0)
                q.push(i);
                
        //performing the simple BFS
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            //adding 'a' to every element to reform that character
            ans += (node+'a');
            
            for(auto it: adj[node])
            {
                //removing that node from each element's indegree it connects to
                indeg[it]--;
                if(indeg[it]==0)
                    q.push(it);
            }
        }
        //returning the answer variable
        return ans;
    }
};