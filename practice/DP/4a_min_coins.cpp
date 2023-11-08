//Coin-Change                                                           Recc.
//Finding min. no. of coins required to make a TARGET amt.
// wherein each coins is present in INFINITE count.

// return -1 if it isnt possible to get the desired amt.

//T.C. O(size(coins) ^ n)
//S.C. O(1)

#include<iostream>
#include<vector>
using namespace std;
int solveRecc(vector<int> &coins, int target) {
    if(target == 0)
        return 0;
    if(target < 0)
        return INT32_MAX;
    
    int min_coins = INT32_MAX;
    for(int i = 0; i< coins.size(); i++){
        int crr = solveRecc(coins, target - coins[i]);

        if(crr != INT32_MAX)
            min_coins = min(min_coins, 1 + crr);
    }

    return min_coins;
}

int minCoins(vector<int> &coins, int target) {
    int res = solveRecc(coins, target);
    if(res == -1)
        return INT32_MAX;
    
    return res;
}

int main()
{
    int n;
    cout<<"\nEnter the diff. types of coins available : ";
    cin>>n;

    vector<int> coins(n);
    cout<<"\nEnter the available denominations :\n";
    for(int i = 0; i<n; i++) {
        cin>>coins[i];
    }

    int target;
    cout<<"\nEnter the reqd. amount : ";
    cin>>target;

    int res = minCoins(coins, target);
    if(res != INT32_MAX)
        cout<<"\nMinimum #coins reqd. to obtain desired amt : "<<res;
    else
        cout<<"\nNOT possible to achieve the reqd. amt!!!";
    return 0;
}