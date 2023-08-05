//Rope Cutting Prob.
//given a str len, and 3 diff part sizes
//calc the max no. of pieces that can be formed out from given len [if possible]
//T.C. O(3^n)   WC
//S.C. 

#include<iostream>
using namespace std;

int calc_pieces(int n, int a, int b, int c) {
    if(n == 0)
        return 0;
    if(n < 0)
        return -1;
    
    int res = max(calc_pieces(n-a,a,b,c), max(calc_pieces(n-b,a,b,c),calc_pieces(n-c,a,b,c)));

    if(res == -1)           //if all 3 recc. calls N.A, gives -1 to parent.
        return -1;
    return res + 1;         //else returns 1 to caller [piece can be broken.]
}

int main()
{
    int n,a,b,c;
    cout<<"\nEnter the n value : ";
    cin>>n;
    cout<<"\nEnter values for a,b,c : ";
    cin>>a>>b>>c;
    int res = calc_pieces(n,a,b,c);
    if(res == -1)
        cout<<"\nNot possible to cut n into given sizes";
    else {
        cout<<"\nYes! It is possible to cut n into sizes of a/b/c.";
        cout<<"\nAlso, max parts that be made of n : "<<res;
    }
    return 0;
}