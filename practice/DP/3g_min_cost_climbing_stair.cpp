//Counting the distinct ways to reach nth stair                         BOTTOM-UP / tabulation 
// {Space Optimization}

// where we can move 1/2 steps ahead at a time.
/*
    1. We can initially start from 0th or 1st stair.
    2. For each step we take in path, we'll have to pay its rental cost
    3. Find min. cost to reach desired step {EXCLUDE cost of reqd. step}
*/
//T.C.  O(n)
//S.C.  O(1)

#include<bits/stdc++.h>
using namespace std;
int target;

int reach_stair(vector<int> &cost) 
{
    int steps = cost.size();
    int curr_cost;
    
    int prev2 = cost[0];
    int prev1 = cost[1];

    for(int i = 2; i < steps; i++){
        curr_cost = cost[i] + min(prev2, prev1);

        prev2 = prev1;
        prev1 = curr_cost;
    }

    return min(curr_cost, prev2);
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
    // doesnt matters to take into account the rental price for n'th stair

    cout<<"\nMin. Cost to reach TARGET stair = "<<reach_stair(cost);
    return 0;
}