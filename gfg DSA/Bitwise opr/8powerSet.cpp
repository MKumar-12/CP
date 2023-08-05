//Generating PowerSet
//T.C. 
//S.C. 

#include<iostream>
using namespace std;

void powerSet(int n) {
    
}

int main()
{
    int arr[100];
    int n;
    cout<<"\nNo. of elements: ";            //6
    cin>>n;
    cout<<"\nEnter values in set : ";              //7 3 7 1 7 7
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    cout<<"\nPowerset is : ";
    powerSet(n);
    return 0;
}