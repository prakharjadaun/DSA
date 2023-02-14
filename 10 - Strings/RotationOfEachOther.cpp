#include<string>
#include<iostream>
#include<vector>
using namespace std;

bool rotate(string s1,string s2, int index)
{
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i] != s2[(index+i)%s1.size()])
            return false;
    }
    return true;
}

int main()
{
    string s1 = "abcd", s2 = "cdab";
    
    if(s1.size()!=s2.size())
    {
        cout<<"Strings are not rotation of each other...!"<<endl;
    }
    else
    {
        char firstch = s1[0];
        vector<int> occur;
        for(int i=0;i<s2.size();i++)
        {
            if(s2[i]==firstch)
                occur.push_back(i);
        }


        bool flag = false;

        for(int index : occur)
        {
            flag = rotate(s1,s2,index);
            if(flag)
                break;
        }

        if(flag)
        {
            cout<<"Rotation of each other...!"<<endl;
        }
        else
        {
            cout<<"Not rotation of each other...!"<<endl;
        }

    }
    return 0;
}