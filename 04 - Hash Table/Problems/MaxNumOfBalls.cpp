#include<algorithm>
#include<climits>
using namespace std;
class Solution {
public:
    int sumOfDigits(int n)
    {
        int count = 0;
        while(n!=0)
        {
            count += n%10;
            n = n/10;
        }
        return count;
    }
    int countBalls(int lowLimit, int highLimit) 
    {
        int arr[46];
        fill(arr,arr+46,0);
        for(int i=lowLimit;i<=highLimit;i++)
        {
            arr[sumOfDigits(i)]++;
        }

        int max_num = INT_MIN;

        for(int i=0;i<46;i++)
        {
            if(arr[i] > max_num)
            {
                max_num = arr[i];
            }
        }
        return max_num;
    }
};