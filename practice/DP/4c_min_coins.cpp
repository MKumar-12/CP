//Coin-Change                                                   Tabulation
//  {BOTTOM-UP approach}
//Finding min. no. of coins required to make a TARGET amt.
// wherein each coins is present in INFINITE count.

// return -1 if it isnt possible to get the desired amt.

//T.C. 
//S.C. 

#include<iostream>
#include<vector>
using namespace std;
int solveTab(vector<int> &coins, int target) {
    vector<int> DP(target + 1, INT32_MAX);
    DP[0] = 0;
    
    for(int j = 1; j <= target; j++){
        for(int i = 0; i < coins.size(); i++){
            if(j - coins[i] >= 0 && DP[j - coins[i]] != INT32_MAX)
                DP[j] = min(DP[j], 1+ DP[j - coins[i]]);
        }
    }
    
}

int minCoins(vector<int> &coins, int target) {
    
    int res = solveTab(coins, target);
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