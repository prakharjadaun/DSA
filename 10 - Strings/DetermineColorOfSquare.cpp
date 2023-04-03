#include<iostream>
using namespace std;
class Solution {
public:
    bool squareIsWhite(string coordinates) 
    {
        return !(((int)(coordinates[0]-'a') % 2) ^ ((int)coordinates[1]) % 2);
    }
};