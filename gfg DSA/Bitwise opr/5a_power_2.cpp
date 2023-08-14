//Chk if given no. is valid power of 2.
//T.C. 
//S.C. 

#include<iostream>
using namespace std;
int ctr =0;

int calc_setbits(int n) {                   //T.C. O(set bits)
    while(n > 0) {
        n = n&(n-1);
        ctr++;
    }
    return ctr;
}

bool validate(int n) {
    if(calc_setbits(n) == 1)
        return true;
    else    
        return false;
}

bool validate_modified(int n) {
    if(n <= 0)
        return false;
    return((n & (n-1)) == 0);
}

int main()
{
    int n;
    cout<<"\nEnter a no.: ";
    cin>>n;
    // if(validate(n))
    if(validate_modified(n))
        cout<<"\nIt is a valid power of 2";
    else
        cout<<"\nNot a power of 2"; 
    return 0;
}