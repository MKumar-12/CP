//Couting set bits using Table, which involves preprocessing
//T.C. O(1)
//S.C. 

#include<iostream>
using namespace std;
int lookup[256];    //initilize

void fill_lookup_table() {          //Preprocessing
    lookup[0] = 0;
    for(int i = 1; i < 256; i++)
    {
        lookup[i] = lookup[i & (i-1)] + 1;
    }
}

int calc_setbits(int n) {           //T.C. O(1)
    return (lookup[n&255] + lookup[(n>>8)&255] + lookup[(n>>16)&255] + lookup[n>>24]);
}

int main()
{
    int n;
    cout<<"\nEnter a no.: ";
    cin>>n;
    fill_lookup_table();
    cout<<"\nNo. of Set bits = "<<calc_setbits(n); 
    return 0;
}