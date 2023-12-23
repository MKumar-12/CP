//Missing Number
//T.C.  O(n)
//S.C.  O(1)

#include<iostream>
#define ll long long
using namespace std;

int main()
{
    ll n;
    cin>>n;

    ll temp,sum = 0;
    sum = (n*(n+1))/2;

    for(ll i = 1; i < n; i++) {
        cin>>temp;
        sum -= temp;
    }

    // cout<<"\nMissing Number: "<<sum;
    cout<<sum;;
    return 0;
}