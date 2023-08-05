//Factorial of a no.
//T.C : O(n)
//T(n) = T(n-1) + 1
//iterative soln is better as it uses theta(1) auxiliary space
//while reccursive soln uses theta(n) aux. space

#include<iostream>
using namespace std;
int fact(int x){                                                //can cause o.f sometimes for larger values of n
    if(x <= 1)
        return 1;
    else 
        return x*fact(x-1);    
}

int main(){
    cout<<"Enter a no. : ";
    int n,res;
    cin>> n;
    if(n >= 0)
    {   
        res = fact(n);
        cout<<"Factorial is : "<<res;
    }
    else
        cout<<"Factorial doesnt exists for -ve no.";
    return 0;
}