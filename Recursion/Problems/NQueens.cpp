#include<iostream>
#include<stdlib.h>
using namespace std;

class Nqueen
{
    private:
        int size;
        int solutions;
    
    public:
        //constructor to assign the inital values to the variables of the class N queen
        Nqueen(int s)
        {
            size = s;
            solutions = 0;
            solve();
        }

        //to assign -1 to all the indices of the positions array
        void assign(int *pos,int n)
        {
            for(int i=0;i<n;i++)
            {
                pos[i] = -1;
            }
        }

        void solve()
        {
            int *positions = (int *)malloc(size*sizeof(int));
            assign(positions,size);

            
        }
};


int main()
{
    int n;
    cout<<"Enter the size of the chess board : ";
    cin>>n;


}