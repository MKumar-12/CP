//Climbing Stairs

/*
        T(n)    = T(n-1) + T(n-2)   ,   n > 2    Fibonacci Series   = (2^n - 1)       
                = 2                 ,   n = 2
                = 1                 ,   n = 1
        
*/
//T.C. 
//S.C. 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // int climbStairs(int n) {                     //  Recursion   T.C.  O(2^n)
    //     if(n <= 2)
    //         return n;
        
    //     return climbStairs(n-1) + climbStairs(n-2);    
    // }

    int climbStairs(int n) {                        //  Using bottom-up DP    T.C.  O(n)
        if(n <= 2)
            return n;
        
        vector<int> dp (n+1, 0);
        dp[1] = 1;
        dp[2] = 2;

        cout<<"\nMemorization table is as follows : "<<endl;
        for(int it = 3; it <= n; it++){
            dp[it] = dp[it-1] + dp[it-2];
            cout<<"dp["<<it<<"] : "<<dp[it]<<endl;
        }

        return dp[n];    
    }
};

int main()
{
    Solution res;
    int top;
    cout<<"\nEnter the #stairs to complete : ";
    cin>>top;
    cout<<"\n\n#ways to reach top : "<<res.climbStairs(top)<<endl;

    return 0;
}