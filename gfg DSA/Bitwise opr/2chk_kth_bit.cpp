//Chk whether kth bit is set or NOT from RHS
//T.C. 
//S.C. 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int len;

bool chk_kth_bit(int n,int k) {
    vector<int> bit_len;
    while(n>0){
        bit_len.push_back(n%2);
        n = n/2;
    }
    //reverse(bit_len.begin(),bit_len.end());

    len = bit_len.size(); 
    // for(auto i =bit_len.begin(); i<bit_len.end();i++) 
    //     cout<<*i;

    return bit_len[k-1];
}

int main()
{
    int n,k;
    cout<<"\nEnter a no. : ";
    cin>>n;
    cout<<"\nEnter the bit to chk its status : ";
    cin>>k;
    if(chk_kth_bit(n,k) && k <= len)
        cout<<"\nYes, it is 1.";
    else 
        cout<<"\nNo, it is 0.";
    return 0;
}