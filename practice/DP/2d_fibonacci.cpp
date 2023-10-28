//Printing nth Fibonacci series using DP                          BOTTOM-UP approach
// {Space Optimization}
//T.C.  O(n)
//S.C.  O(1)


//  0 1 1 2 3 5 8 13 21 34 55 ...

#include<iostream>
#include<vector>
#include<cstring>
using namespace std; 

int fibo(int n) {
    if(n <= 1)
        return n;

    int curr;

    // base-cases
    int prev2 = 0;
    int prev1 = 1;
    
    // cout<<"\n0 1 ";
    for(int i = 2; i < n+1; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
        // cout<<curr<<" ";
    }

    // return reqd. element
    return curr;
}

int main()
{
    int reqd;
    cout<<"\nEnter the reqd. element of Fibonacci series : ";
    cin>>reqd; 

    cout<<"\n"<<fibo(reqd)<<" is "<<reqd<<"'th element in fibonacci series!";
    return 0;
}