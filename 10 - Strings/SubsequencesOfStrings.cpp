#include<iostream>
using namespace std;
void printSubsequence(string input, string output)
{
    if(input.empty())
        cout<<output<<endl;
    else
    {
        //output is passed with including the first character of the input string
        printSubsequence(input.substr(1),output + input[0]);
        //output is passed without including the first character of the input string
        printSubsequence(input.substr(1),output);
    }
}
int main()
{
    string input ="hello",output="";
    printSubsequence(input,output);
}