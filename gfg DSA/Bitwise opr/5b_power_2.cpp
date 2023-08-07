//Chking if a given no. is valid power of 2
//T.C. 
//S.C. 

#include<iostream>
using namespace std;

bool validate(int n) {
    if(n == 0)
        return false;
    
    while(n%2 == 0) n/=2;            //flushes out odd no.

    return (n == 1);
}

int main()
{
    int n;
    cout<<"\nEnter a no.: ";
    cin>>n;
    if(validate(n))
        cout<<"\nIt is a valid power of 2";
    else
        cout<<"\nNot a power of 2"; 
    return 0;
}