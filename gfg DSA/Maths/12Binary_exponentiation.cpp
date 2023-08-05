//a^n
//T.C. O(log n)
//S.C. O(1)

#include<iostream>
using namespace std;

int bin_exp(int a, int n) {                    //iterates over bits in binary representation of 'n'
    //increases base-val of a as 1, 2, 4, n so on.....
    //lastly adds the values having bin. bit value as 1
    int res = 1;
    while(n > 0) {
        if(n%2 != 0)                //bit = 1         OR    (n&1) BITWISE AND
            res *= a;
    
        a = a*a;
        n= n/2;
        // or n>>1;       LEFT SHIFTING n by 1 bit
    }
    return res;
}


//use long long if power value too high, i.e. out of int bound
int main()
{
    int a,n,res;
    cout<<"Enter a no. and raise to power : ";
    cin>>a>>n;
    res = bin_exp(a,n);
    cout<<a<<"^"<<n<<" = "<<res;
    return 0;
}