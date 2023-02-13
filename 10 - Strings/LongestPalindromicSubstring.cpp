#include<iostream>
using namespace std;

bool checkPalindrome(string str)
{
    int i=0,j=str.size()-1;
    char ch;
    while(i<j)
    {
        if(str[i] != str[j])
            return false;

        i++;
        j--;
    }
    return true;
}

void allSubString(string str,int n)
{
    int min_len = 0;
    string ans ="",temp;
    for (int i = 0; i < n; i++)
    {
        for (int len = 1; len <= n - i; len++)
        {
            temp = str.substr(i, len);
            cout<<temp<<endl;
            if(checkPalindrome(temp)) 
            {
                if(temp.size() > min_len)
                {
                    min_len = temp.size();
                    ans = temp;
                }
            }
        }
    }

    cout<<"Longest palindromic substring : "<<ans<<endl;
}

int main()
{
    string str = "aaaabbaa";
    allSubString(str,str.size());
}