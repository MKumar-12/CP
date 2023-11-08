//Counting the distinct ways to reach nth stair                         TOP-DOWN + memoization
// where we can move 1/2 steps ahead at a time.
/*
    1. We can initially start from 0th or 1st stair.
    2. For each step we take in path, we'll have to pay its rental cost
    3. Find min. cost to reach desired step {EXCLUDE cost of reqd. step}
*/
//T.C.  O(n)
//S.C.  O(n) + O(n)     ~   O(n)

#include<bits/stdc++.h>
using namespace std;
int target;

int solve(vector<int> &cost, int curr, vector<int> &DP){
    //BASE CASES
    if(curr == 0)
        return cost[0];
    else if(curr == 1)
        return cost[1];
 
    //Step 3
    if(DP[curr] != -1)
        return DP[curr];

    //Step 2
    return DP[curr] = cost[curr] + min(solve(cost, curr - 1, DP), solve(cost, curr - 2, DP));
}

int reach_stair(vector<int> &cost) 
{
    int steps = cost.size();
    //Step 1
    vector<int> DP(steps + 1, -1);

    return min(solve(cost, steps-1, DP), solve(cost, steps-2, DP));
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

    cout<<"\nMin. Cost to reach TARGET stair = "<<reach_stair(cost);
    return 0;
}

/*
10
1 100 1 1 1 100 1 1 100 1

8
2 3 4 2 8

5
4 2 1 6 2
*/