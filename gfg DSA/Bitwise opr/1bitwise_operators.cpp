//Bitwise operators 
//T.C. 
//S.C. 

#include<iostream>
using namespace std;

int main()
{
    int a, b;
    cout<<"Enter a , b : ";
    cin>>a>>b;
    int res = a&b;
    cout<<"\nBitwise AND is : "<< res;
    
    res = a|b;
    cout<<"\nBitwise OR is  : "<< res;
    
    res = a^b;
    cout<<"\nBitwise XOR is : "<< res; 

    cout<<"\n\nLEFT-SHIFT Operator\n";
    res = a<<1;
    cout<<a<<" left-shift 1-bit : "<< res<<endl;
    res = a<<2;
    cout<<a<<" left-shift 2-bit : "<< res;

    cout<<"\n\nRIGHT-SHIFT Operator\n";    
    res = b>>1;
    cout<<b<<" right-shift 1-bit : "<< res<<endl;
    res = b>>2;
    cout<<b<<" right-shift 2-bit : "<< res;

    cout<<"\n\nBitwise NOT Operator";
    signed int p = 2;
    res = ~p;
    cout<<"\nNOT of signed int   "<<p<<" is : "<< res;
    
    unsigned int q =2;
    res = ~q;
    cout<<"\nNOT of unsigned int "<<q<<" is : "<< res;
    
    return 0;
}