//Counting the distinct ways to reach nth stair                 BOTTOM-UP recc.
// where we can move 1/2 steps ahead at a time.
//T.C.  O(2^n)
//S.C.  O(1)

#include<bits/stdc++.h>
using namespace std;

int reach_stair(int target, int curr) 
{
    if(curr == target)
        return 1;
    
    else if(curr > target)
        return 0;

    return reach_stair(target, curr + 1) + reach_stair(target, curr + 2); 
}

int main()
{
    int target;
    cout<<"\nEnter Target stair : ";
    cin>>target;

    cout<<"\n#Ways to reach TARGET stair = "<<reach_stair(target,0);
    return 0;
}


/*  Target Stair : [3]
    1 2
    2 1
    1 1 1
*/

/*  [4]
    1 1 1 1 
    1 2 1 
    2 1 1 
    1 1 2 
    2 2 
*/

/*  [5]
    1 1 1 1 1
    1 1 1 2
    1 1 2 1
    1 2 1 1
    2 1 1 1
    1 2 2
    2 1 2
    2 2 1
*/