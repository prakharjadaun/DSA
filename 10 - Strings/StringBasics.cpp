#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    // char str[30];
    string str;
    int n ;
    printf("Enter the number : ");
    scanf("%d",&n);

    while(getchar()!='\n');
    printf("Enter the string : ");
    // scanf("%s",str);
    // gets(str);
    // fgets(str,30,stdin);
    getline(cin,str);
    // cin>>str;

    cout<<str<<endl;
    for(int i=0;str[i]!='\0';i++)
    {
        if(islower(str[i]))
        {
            str[i] = str[i] - 32;
        }
    }

    cout<<str<<endl;
    return 0;
}