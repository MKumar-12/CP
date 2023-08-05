//GCD/HCF of 2 no.
//even non-prime integers can have GCD as 1, i.e. 9 n 10

#include<iostream>
using namespace std;
int gcd1(int x, int y){                                     //Euclidean algo T.C = O(n)            
    if(x == y)
        return x;
    else if(x > y)
        return gcd1(x-y, y);
    else    
        return gcd1(x, y-x); 
}

int gcd2(int p, int q){                                     //naive soln. T.C = O(min(a,b))
    int res = min(p,q);
    while(res > 0){
        if(p % res == 0 && q % res == 0)
            break;
        res--;
    }
    return res;
}

int gcd3(int m, int n){                                    //T.C. O( log(min[a,b]) ) 
    //works on modular division
    if(n == 0)                              //n always becomes 0 1st
        return m;
    else
        return gcd3(n, m%n);                //swaps m,n in 1st call if m < n
}


int main()
{
    int a, b,res = 0;
    cout<<"Enter 2 no. : ";
    cin>>a>>b;
    //res = gcd1(a,b);
    //res = gcd2(a,b);
    res = gcd3(a,b);
    cout<<"GCD is : "<<res;
    return 0;
}