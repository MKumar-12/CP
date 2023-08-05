//Pallindrome no.
//T.C : theta(digits)

#include<iostream>
using namespace std;

int main(){
    int n,rev=0,temp;
    cout<<"Enter a no. : ";
    cin>> n;
    temp = n;
    while(temp>0){
        rev = (rev*10) + temp%10;           //left shift crr_value by 1 place to LEFT
        temp = temp/10;                     //chops off last digit 1 by 1
    }

    if(rev == n)    
        cout<<"\nNo. is pallindrome";
    else
        cout<<"\nNo. is NOT pallindrome";

    //cout<<(bool)(rev==n);
    return 0;
}