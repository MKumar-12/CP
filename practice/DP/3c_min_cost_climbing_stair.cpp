//Counting the distinct ways to reach nth stair
// where we can move 1/2 steps ahead at a time.
/*
    1. We can initially start from 0th or 1st stair.
    2. For each step we take in path, we'll have to pay its rental cost
    3. Find min. cost to reach desired step {EXCLUDE cost of reqd. step}
*/
//T.C.  O(2^n)
//S.C.  O(1)

/*
    WRONG IMPLEMENTATION

    for i/p :
    target  = 5
    cost    = 2 3 4 2 8

    gives output as 14                   {i.e. 2 - 4 - 8 }
    But, expected output should be 13    {i.e. 3 - 2 - 8 }
*/

#include<bits/stdc++.h>
using namespace std;
int target;

int reach_stair(vector<int> &cost, int curr) 
{
    if(curr > target)
        return 0;

    else if(curr == target)
        return cost[target];

    return cost[curr] + min(reach_stair(cost, curr + 1), reach_stair(cost, curr + 2)); 
}

int main()
{
    cout<<"\nEnter Target stair : ";
    cin>>target;

    vector<int> cost (target, 0);
    cout<<"\nEnter the rental cost for :";
    for(int i = 0; i < target; i++){
        cout<<"\nStair "<< i + 1 <<" : ";
        cin>>cost[i];        
    }

    int start_stair;
    if(min(cost[0], cost[1]) == cost[0])
        start_stair = 0;
    else
        start_stair = 1;

    cout<<"\nMin. Cost to reach TARGET stair = "<<reach_stair(cost, start_stair);
    return 0;
}
