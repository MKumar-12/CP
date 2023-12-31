//Counting the distinct ways to reach nth stair                 TOP-DOWN recc.
// where we can move 1/2 steps ahead at a time.
//T.C.  O(2^n)
//S.C.  O(1)

#include<bits/stdc++.h>
using namespace std;

int reach_stair(int target) 
{
    if(target <= 0)
        return 0;
    
    else if(target == 1)
        return 1;

    else if(target == 2)
        return 2;

    return reach_stair(target-1) + reach_stair(target-2); 
}

int main()
{
    int target;
    cout<<"\nEnter Target stair : ";
    cin>>target;

    cout<<"\n#Ways to reach TARGET stair = "<<reach_stair(target);
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