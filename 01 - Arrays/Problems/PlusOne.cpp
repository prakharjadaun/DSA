#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        //if the last digit of the vector contains value less than 9 then add 1 to it and return the passed vector
        if(digits[digits.size()-1]<9)
        {
            digits[digits.size()-1] += 1;
            return digits;
        }    
        //else we need to add carry one 
        int carry=1;
        int i=digits.size()-1;
        //iterating from the last element and if we encounter a number with which if we add carry 1 it gives us 10
        //then we will set it to 0 and reassigning the carry with 1
        //when the carry becomes 0, we break the loop and return the modified array digits
        while(i>-1)
        {
            if(digits[i]+carry == 10)
            {
                digits[i] = 0;
                carry = 1;
            }
            else if(digits[i]+1 != 10)
            {
                digits[i] += 1;
                carry =0;
                break;
            }
            i--;
        }
        //if the carry is not 0 after modifying the whole array, then we insert 1 to its first position
        if(carry!=0)
        digits.insert(digits.begin(),1);

        return digits;
    }
};