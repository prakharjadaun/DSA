#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dis(m,vector<int>(n,0));
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    vis[i][j] = 1;
                    q.push({{i,j},0});
                }
            }
        }

        vector<int> dr = {-1,0,1,0};
        vector<int> dc = {0,-1,0,1};

        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            dis[r][c] = d;
            q.pop();

            for(int i=0;i<4;i++)
            {
                int nrow = r + dr[i];
                int ncol = c + dc[i];

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol]==0)
                {
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},d+1});
                }
            }
        }
        return dis;
    }
};