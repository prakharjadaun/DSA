#include<vector>
using namespace std;

class Solution {
public:
    //time complexity: O(nxm) (in worst case you would be reaching all the nodes or cells. Also, you will be performing O(4 x (nxm))) searches 
    void DFS(vector<vector<int>> &image,vector<vector<int>> &ans,int oldcol,int i, int j, int newcol)
    {
        //get the size of the matrix
        int m = image.size();
        int n = image[0].size();
        //check if the indices are not exceeding the limits and also if the ans (i,j) contains that newcol
        if(i<0 || j<0 || i==m || j==n || ans[i][j]==newcol)
            return;
        //if the i,j points to oldcol, then assign the new color
        if(image[i][j]==oldcol)
            ans[i][j] = newcol;
        else
            return;
        //check the same for the 4-directional indices for the current indices
        DFS(image,ans,oldcol,i-1,j,newcol);
        DFS(image,ans,oldcol,i+1,j,newcol);
        DFS(image,ans,oldcol,i,j-1,newcol);
        DFS(image,ans,oldcol,i,j+1,newcol);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        //store the initial color
        int oldcol = image[sr][sc];
        //create an answer matrix in which we will change the old color with new color
        vector<vector<int>> ans = image;
        //call the dfs or flood fill algorithm
        DFS(image,ans,oldcol,sr,sc,color);
        return ans;
    }
};