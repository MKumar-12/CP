//Printing nth Fibonacci series using DP {recc. + MEMOIZATION}      TOP-DOWN approach
// {Vector implmentation}
//T.C.  O(n)
//S.C.  O(n)

#include<iostream>
#include<vector>
#include<cstring>
using namespace std; 
vector<int> DP(101);

int fibo(int n, vector<int> &DP) {
    if(n == 0 || n == 1)
        return n;

    if(DP[n] != -1)
        return DP[n];
    
    DP[n] = fibo(n-1, DP) + fibo(n-2, DP);
    return DP[n];
}

int main()
{
    int reqd;
    cout<<"\nEnter the reqd. element of Fibonacci series : ";
    cin>>reqd; 

    for(int i = 0; i < 101; i++) {
        DP[i] = -1;
    }

    cout<<"\n"<<fibo(reqd, DP)<<" is "<<reqd<<"'th element in fibonacci series!";
    return 0;
}