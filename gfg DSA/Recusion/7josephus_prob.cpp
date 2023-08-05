//Josephus prob
//n ppl in a circle
//kth person is removed/killed in each iteration (in circular manner)
//find position of survivor after performing the same
//T.C. O(n)
//T(n) = T(n-1) + c

#include<iostream>
using namespace std;

//considering cicle posi. begins with 0
int jose0(int n, int k) {
    if(n == 1)
        return 0; 

    return(jose0(n-1,k) + k)% n;
}

int main()
{
    int n,k;
    cout<<"\nEnter the no. of ppl : ";
    cin>>n;
    cout<<"\nkth value: ";
    cin>>k;
    // cout<<"\nSurvivor is : "<<jose0(n,k)<<"th person.";
    
    //considering cicle posi. begins with 1
    cout<<"\nSurvivor is : "<<jose0(n,k) + 1<<"th person.";
    return 0;
}