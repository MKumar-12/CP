//LCM of 2 no.
//

//a*b = gcd(a,b) * lcm(a,b)         IMP.

#include<iostream>
using namespace std;

int gcd(int p, int q) {
    if(q == 0)
        return p;
    else 
        return gcd(q, p%q);
}

int lcm1(int x, int y){                               //Euclidean algo T.C = O( log(min[x,y]) )            
    
    int res = gcd(x,y);
    return (x*y)/ res;    
}

int lcm2(int p, int q){                               //naive soln. T.C = O(p*q - max(p,q))
    int res = max(p,q);
    while(true){
        if(res % p == 0 && res % q == 0)
            break;
        res++;
    }
    return res;
}


int main()
{
    int a, b,res = 0;
    cout<<"Enter 2 no. : ";
    cin>>a>>b;
    res = lcm1(a,b);
    //res = lcm2(a,b);
    cout<<"LCM is : "<<res;
    return 0;

}