// Min. changes to make alternating bin. string seq.
//T.C.  O(n) 
//S.C.  O(1)

#include<bits/stdc++.h>
using namespace std;

int minOperations(string s) {
    int ctr1 = 0, ctr2 = 0;

    for(int i = 0; i < s.size(); i++) {
        if(i % 2 == 1 && s[i] == '0')
            ctr1++;
        else if(i % 2 == 0 && s[i] == '1')
            ctr1++;
        else if(i % 2 == 1 && s[i] == '1')
            ctr2++;
        else if(i % 2 == 0 && s[i] == '0')
            ctr2++;
    }

    return min(ctr1,ctr2);
}

int main()
{
    string str;
    cout<<"\nEnter a bin. string : ";
    cin>>str;

    cout<<"\nMin. Operations reqd. : "<<minOperations(str);
    return 0;
}

/*
0100
*/