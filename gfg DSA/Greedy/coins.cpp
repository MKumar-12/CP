//  GREEDY algo.

// Given some INF amt. of coins, and a desired sum
// return the min. no. of coins that are required to compute the sum.

// may not return result for some cases wherein we have utilized a higher val. object
// and the result is now not obtainable from remaining smaller values.
// Although a soln. was possible if we had excluded larger one.

/*
    Doesnt always guareentees a correct/optimal result  
    i.e, coins  = {18,1,10}
         Amt.   = 20

        Then, acco. to greedy we'll output 3 coins reqd.
                Although the sum can be obtained with even 2 coins of rs.10
*/




//T.C.  O(n logn)
//S.C. 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int getcoins(vector<int> coins, int amt){
    int res = 0, ctr = 0;
    for(int i = 0; i<coins.size(); i++){
        if(coins[i] <= amt){
            ctr = amt/coins[i];
            res += ctr;
            amt = amt - ctr*coins[i];
            cout<<"\nUsed "<<ctr<<" coins of value "<<coins[i];
        }
        if(amt == 0)
            break;
    }
    
    if(amt == 0)
        return res;
    else { 
        cout<<"\n\nRemaining amt. to transact after applying operations : "<<amt;;
        return -1;
    }
}



int main()
{
    int n,temp;
    vector<int> cost;
    cout<<"\nEnter the count of various currency present : ";       //  4
    cin>>n;
    cout<<"\nEnter your currencies : "<<endl;                       //  1 5 2 10
    for(int i = 0; i < n ; i++){
        cin>>temp;
        cost.push_back(temp);
    }

    sort(cost.begin(), cost.end(), greater<int>());
    cout<<"\nDescending Sorted order of i/p currencies is as follows :"<<endl;
    for(auto i:cost)
        cout<<i<<" ";
    
    int amt;
    cout<<"\n\nEnter the required amt. :  ";                        //  57
    cin>>amt;

    //Calc. of min reqd coins for obtaining the given sum.
    int min_coins = getcoins(cost,amt);
    if(min_coins == -1)
        cout<<"\n\nAmt. NOT possible to obtain from given currencies!!";
    else
        cout<<"\n\nMin. no. of coins required to obtain "<<amt<<" as sum is : "<<min_coins; 

    return 0;
}