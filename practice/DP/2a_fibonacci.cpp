//Printing nth Fibonacci series using DP {recc. + MEMOIZATION}      TOP-DOWN approach
//T.C.  O(n)
//S.C.  O(n)

#include<iostream>
#include<vector>
#include<cstring>
using namespace std; 
int DP[101];

int fibo(int n) {
    if(n == 0 || n == 1)
        return n;

    if(DP[n] != 0)
        return DP[n];
    
    return DP[n] = fibo(n-1) + fibo(n-2);
}

int main()
{
    int reqd;
    cout<<"\nEnter the reqd. element of Fibonacci series : ";
    cin>>reqd; 

    memset(DP, -1, sizeof(DP));
    
    cout<<"\n"<<fibo(reqd)<<" is "<<reqd<<"'th element in fibonacci series!";
    return 0;
}