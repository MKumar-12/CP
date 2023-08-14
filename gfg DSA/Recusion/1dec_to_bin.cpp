//Decimal to binary Eqw.
//T.C. 
//S.C. 

#include<iostream>
using namespace std;

void bin(int n) {
    if(n == 0)
        return;
    bin(n/2);
    cout<<n%2;
}

int main()
{
    int n; 
    cout<<"\nEnter a no. : ";
    cin>>n;
    cout<<"Following is its binary eqw. : \t";
    bin(n);
    return 0;
}