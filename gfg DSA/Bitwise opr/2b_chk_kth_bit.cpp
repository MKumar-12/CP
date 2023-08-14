//Chk whether kth bit is set or NOT from RHS
//T.C. 
//S.C. 

#include<iostream>
#include<math.h>
using namespace std;
int len;

bool chk_kth_bit(int n,int k) {
    // int var2 = pow(2,k-1);
    // int res = n & var2;

    //OR
    int final = n>>(k-1); 
    int res = final & 1;
    return res;
}

int main()
{
    int n,k;
    cout<<"\nEnter a no. : ";
    cin>>n;
    cout<<"\nEnter the bit to chk its status : ";
    cin>>k;
    if(chk_kth_bit(n,k))
        cout<<"\nYes, it is 1.";
    else 
        cout<<"\nNo, it is 0.";
    return 0;
}