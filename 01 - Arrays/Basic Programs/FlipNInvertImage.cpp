#include<vector>
using namespace std;
#include<algorithm>
class Solution {
public:
//  first reverse each row and then replace ones by zeros and zeros by ones
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) 
    {
        for(int i=0;i<image.size();i++)
        {
            reverse(image[i].begin(),image[i].end());
            for(int j=0;j<image[i].size();j++)
            {
                if(image[i][j]==0)
                    image[i][j]=1;
                else
                    image[i][j]=0;
            }
        }    
        return image;
    }
};