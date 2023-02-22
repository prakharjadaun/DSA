#include <unordered_set>
using namespace std;

bool subArrayExists(int arr[], int n)
{
    unordered_set<int> hashset;
    int presum = 0;
    for (int i = 0; i < n; i++)
    {
        presum += arr[i];

        if (presum == 0 || hashset.find(presum) != hashset.end())
            return true;

        hashset.insert(presum);
    }
    return false;
}