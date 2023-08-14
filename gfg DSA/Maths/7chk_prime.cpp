//Chk for prime
//T.C. O( sqrt(n) )

#include <bits/stdc++.h>
using namespace std;

bool chk_prime(int x) {
    for(int i = 2; i <= sqrt(x); i++) {
        if(x%i == 0)
            return true;
    }
    return false;
}

bool chk_prime_optimized(int x) {                   //almost x3 times faster than sqrt(n) approach
    if(x==2 || x==3)
        return false;
    if(x%2==0 || x%3==0)
        return true;
    for(int i = 5; i <= sqrt(x); i+6) {
        if(x%i == 0 || x%(i+2) == 0)
            return true;
    }
    return false;
}

int main()
{
    int n;
    bool res;
    cout<<"Enter a no. : ";
    cin>>n;
    if(n == 1)
        cout<<"\nNeither prime nor composite";
    else {
        res = chk_prime(n);
        if(res)
            cout<<"\nNot a prime no.";
        else
            cout<<"\nIt is a prime no.";
    }
    return 0;
}