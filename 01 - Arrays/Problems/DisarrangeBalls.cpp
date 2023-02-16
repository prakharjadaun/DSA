class Solution{
public:
    
    long int disarrange(int N)
    {
        // code here
        if(N==0 || N==1)
            return 0;
        if(N==2)
            return 1;
        return (((N-1) * disarrange(N-1)) % 1000000009) + (disarrange(N-2)) % 1000000009;
        
    }
};