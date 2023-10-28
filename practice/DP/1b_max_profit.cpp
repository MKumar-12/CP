// 0/1 KS   {using recc. + MEMOIZATION} / TOP-DOWN
// Max-profit Calculation 
//T.C.  O(2^n)
//S.C.  O(n)            {for reccursive fn. call stack}

#include<iostream>
#include<cstring>
using namespace std;
static int DP[101][1001];    

int calc_profit(int weights[], int values[], int n, int capacity) 
{
    if(n == 0 || capacity == 0)
        return 0;

    if(DP[n][capacity] != -1)
        return DP[n][capacity];

    if(weights[n-1] > capacity)
        return DP[n][capacity] = calc_profit(weights, values, n-1, capacity);

    //computes for each element whether its beneficial to add it to SACK or not.
    int include = values[n-1] + calc_profit(weights, values, n-1, capacity - weights[n-1]);
    int exclude = calc_profit(weights, values, n-1, capacity);

    return DP[n][capacity] = max(include, exclude);
}

int main()
{
    int n,cap;
    cout<<"\nEnter no. of items : ";             // 4
    cin>>n;

    int wt[n],val[n];
    cout<<"\nEnter Wt. and Values for respective items : ";
    for(int i=0; i<n; i++){
        cout<<"\nItem "<<i+1<<" : ";
        cin>>wt[i]>>val[i];
    }
    //  1 1 3 4 4 5 5 7

    cout<<"\nEnter max. CAPACITY : ";           // 7
    cin>>cap;

    memset(DP, -1, sizeof(DP));
    cout<<"\nMax. Achievable profit : "<<calc_profit(wt,val,n,cap);

    cout<<"\n\nDP table is as follows : "<<endl;
    for (int i = 0; i < n+1; i++)
    {
        for(int j = 0; j < cap+1; j++)
            cout<<DP[i][j]<<" ";
        cout<<"\n";
    }
     
    return 0;
}