class Solution {
public:
    int tribonacci(int n)
    {
        int arr[3];
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 1;
        for(int i=3;i<=n;i++){
            // cout<<arr[0]<<endl;
            // cout<<arr[1]<<endl;
            // cout<<arr[2]<<endl;
            // cout<<endl;
            arr[i%3] = arr[(i-1)%3] + arr[(i-2)%3] + arr[(i-3)%3];
        
        }

        return arr[n%3];
    }
};