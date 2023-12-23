//Weird algorithm
//T.C. 
//S.C. 

/*
Recc. reln.
T(n)    = T(n/2)        , if n even
        = 3T(n) + 1     , if n odd
        = 1             , if n = 1 
*/


#include<iostream>
using namespace std;
#define ll long long 

void recurse(ll x){
    if(x == 1)
        return;
    
    cout<<x<<" ";
    if(x%2 == 0)
        recurse(x/2);
    else 
        recurse(3*x + 1);
}

int main()
{
    ll n;
    cin>>n;

    recurse(n);
    cout<<1;

    return 0;
}


/*
=========================================================================================
OR
=========================================================================================

int main()
{
    ll n;
    cin>>n;

    cout<<n;
    while(n > 1){
        if(n % 2 == 0)
            n = n/2;
        else
            n = 3*n + 1;
        
        cout<<" "<<n;
    }

    return 0;
}

=========================================================================================
*/