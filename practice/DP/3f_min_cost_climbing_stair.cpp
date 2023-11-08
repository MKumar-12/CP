//Counting the distinct ways to reach nth stair                         BOTTOM-UP / tabulation 
// where we can move 1/2 steps ahead at a time.
/*
    1. We can initially start from 0th or 1st stair.
    2. For each step we take in path, we'll have to pay its rental cost
    3. Find min. cost to reach desired step {EXCLUDE cost of reqd. step}
*/
//T.C.  O(n)
//S.C.  O(n)

#include<bits/stdc++.h>
using namespace std;
int target;

int reach_stair(vector<int> &cost) 
{
    int steps = cost.size();
    
    vector<int> DP(steps + 1, -1);

    DP[0] = cost[0];
    DP[1] = cost[1];

    for(int i = 2; i < steps + 1; i++){
        DP[i] = cost[i] + min(DP[i-1], DP[i-2]);
    }

    return min(DP[steps-1], DP[steps-2]);
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

/*
10
1 100 1 1 1 100 1 1 100 1

5
2 3 4 2 8

5
4 2 1 6 2
*/