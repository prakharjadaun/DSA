#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    //function to tell whether the points is inside the circle or not
    bool isInside(int x,int y, int r, int circle_x,int circle_y)
    {
        if((x-circle_x)*(x-circle_x) + (y-circle_y)*(y-circle_y) <= (r*r))
        return true;
        else
        return false;
    }
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) 
    {
        int temp;
        vector<int> ans;
        for(int i=0;i<queries.size();i++)
        {
            temp = 0;
            //iterating through all points and getting the count of number of points inside the circle
            for(int j=0;j<points.size();j++)
            {
                if(isInside(points[j][0],points[j][1],queries[i][2],queries[i][0],queries[i][1]))
                temp++;
            }
            //storing the count inside the ans vector
            ans.push_back(temp);
        }
        //returning the ans vector
        return ans;
    }
};