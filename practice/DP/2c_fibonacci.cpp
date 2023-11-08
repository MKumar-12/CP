//Printing nth Fibonacci series using DP                            BOTTOM-UP approach
// {Vector implmentation}
//T.C.  O(n)
//S.C.  O(n)

#include<iostream>
#include<vector>
using namespace std; 

int fibo(int n) {
    vector<int> DP(n+1, -1);                    // S.C -> only for creation of vector ~ O(n)
    
    // initialization   {NOT REQUIRED}
    // for(int i = 0; i < n+1; i++) {
    //     DP[i] = -1;
    // }

    // base-cases
    DP[0] = 0;
    DP[1] = 1;
    
    // tabulation
    for(int i = 2; i < n+1; i++) {
        DP[i] = DP[i-1] + DP[i-2];
    }

    // return reqd. element
    if(DP[n] != -1)
        return DP[n];
}

int main()
{
    int reqd;
    cout<<"\nEnter the reqd. element of Fibonacci series : ";
    cin>>reqd; 

    cout<<"\n"<<fibo(reqd)<<" is "<<reqd<<"'th element in fibonacci series!";
    return 0;
}