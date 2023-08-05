//#set-bits
//T.C. 
//S.C. 

//Bitwise operators are faster than logical operators.

#include<iostream>
using namespace std;
int ctr = 0;

int set_bits(int n) {                                   //T.C. theta(#bits or d)
    while(n>0) {
        if(n&1 != 0)            //chks if last bit SET
            ctr++;

        //OR ctr += (n&1);
        n = n>>1;               //right-shift by 1 place
    }
    return ctr;
}

//Traverses only through set-bits
int set_bits_modified(int n) {                          //T.C. theta(#set-bits)
    while(n>0) {
        n = n & (n-1);                   //makes last set bit from RHS as 0
        /*
        i.e.,
                40 :    101000
                39 :    100111
            &     -->   100000  : removes the last set bit from RHS 
        */
        ctr++;              
    }
    return ctr;
}

int main()
{
    int n;
    cout<<"\nEnter a no. : ";
    cin>>n;
    //cout<<"\nNo. of set bits are : "<<set_bits(n);
    cout<<"\nNo. of set bits are : "<<set_bits_modified(n);
    
    return 0;
}