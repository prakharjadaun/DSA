#include<vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        //median -> 
        //sort the numbers 
        //if the numbers are odd, return the middle element as the median
        //if the numbers are even, return the mean of the two middle elements that is n/2th and (n/2)+1 th element
        vector<int> ans;
        //if the first vector is 0, then find the median of second vector and return it 
        if(nums1.size()==0)
        {
            if(nums2.size()%2==0)
            {
                return (double)(nums2[(nums2.size()/2)-1] + nums2[(nums2.size()/2)])/2;
            }
            else
                return (double)(nums2[nums2.size()/2]);
        }    
        //if the second vector is 0, then find the median of first vector and return it
        if(nums2.size()==0)
        {
            if(nums1.size()%2==0)
            {
                return (double)(nums1[(nums1.size()/2)-1] + nums1[(nums1.size()/2)])/2;
            }
            else
                return (double)(nums1[nums1.size()/2]);
        }

        int i=0,j=0;
        //create a new vector having sorted numbers of both the arrays
        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i] < nums2[j])
            {
                ans.push_back(nums1[i]);
                i++;
            }
            else
            {
                ans.push_back(nums2[j]);
                j++;
            }
        }

        while(i<nums1.size())
        {
            ans.push_back(nums1[i]);
            i++;
        }
        while(j<nums2.size())
        {
            ans.push_back(nums2[j]);
            j++;
        }
        //finally return the median of the newly created vector with the same logic
        if(ans.size()%2==0)
        {
            return (double)(ans[(ans.size()/2)-1] + ans[(ans.size()/2)])/2;
        }
        else
            return (double)(ans[ans.size()/2]);
    }
};