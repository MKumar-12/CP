//Digit count       
//T.C : Theta(digits) 

#include<iostream>
using namespace std;

int main()
{
        int n,digits = 0;
        cout<<"Enter a no. : ";
        cin>>n;
        while(n > 0){
            n = n/10;
            digits++;
        }
        cout<<"\nNo. of digits is : "<<digits;
}