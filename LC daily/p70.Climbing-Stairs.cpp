//
//T.C. 
//S.C. 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Using RECURSION (can cause TLE)
    // int climbStairs(int n) {
    //     if(n < 1)
    //         return 0;
        
    //     if(n == 1) 
    //         return 1;
    //     else if(n == 2)
    //         return 2;

    //     return climbStairs(n-1) + climbStairs(n-2);
    // }

    // MEMORIZATION
    int climbStairs(int n) {
        int steps[46];
        // initialization
        steps[0] = 1;
        steps[1] = 2;

        // iteratively calculating remaining values
        for(int i = 2; i < n; i++) {
            steps[i] = steps[i-1] + steps[i-2];
        }

        return steps[n-1];
    }
};


/*      RECURSION
f4: f3 + f2  -> 5
f3: f2 + f1  -> 3
f2: 2
f1: 1
*/

int main()
{
    int n;
    cout<<"\nEnter no. of Steps presents : ";
    cin>> n;

    Solution S;
    cout<<"\n\n#ways to reach : "<<S.climbStairs(n);
    return 0;
}