//a^n
//T.C. O(log n base-2) 
//S.C. O(log n base-2) for recc. calls made

#include<iostream>
using namespace std;

int calc_power(int a, int n) {                  //Naive Soln.   T.C. Theta(n)
    if(n == 0)
        return 1;
    
    int res=1;
    for(int i =1; i<=n; i++) 
        res *= a;

    return res;
}

int calc_power_optimized(int a, int n) {                  //T.C. O(log n base-2)
    if(n == 0)
        return 1;
    
    int temp = calc_power_optimized(a,n/2);

    if(n%2 == 0)  
        return temp * temp; 
    else    
        return a * temp * temp;
}

int main()
{
    int a,n,res;
    cout<<"Enter a no. and raise to power : ";
    cin>>a>>n;
    //res = calc_power(a,n);
    res = calc_power_optimized(a,n);
    cout<<a<<"^"<<n<<" = "<<res;
    return 0;
}