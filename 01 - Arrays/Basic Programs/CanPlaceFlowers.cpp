#include<vector>
using namespace std;
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        int places = 0;
        if(flowerbed.size()==1 && flowerbed[0]==0)
        {
            places = 1;
            if(places >= n)
                return true;
        }
        for(int i=0;i<flowerbed.size();i++)
        {
            if(flowerbed[i]==1)
                continue;
            
            if(i-1 >=0 && i+1 < flowerbed.size())
            {
                if(flowerbed[i-1]==0 && flowerbed[i+1]==0)
                {
                    places++;
                    i++;
                }
            }
            else if(i==0 && i+1 < flowerbed.size())
            {
                if(flowerbed[i+1]==0)
                    places++;
                    i++;
            }
            else if(i == flowerbed.size()-1 && i-1>=0)
            {
                if(flowerbed[i-1]==0)
                    places++;
            }
        }    

        if(places >= n)
            return true;
        return false;
    }
};