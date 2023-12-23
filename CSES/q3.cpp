//Repetitions 
//T.C.  O(n)
//S.C.  O(1)

#include<iostream>
using namespace std;

int max_rep(string s) {
    int ctr, res = 0,i = 0,j = 1;
    int len = s.length();
    for(i = 0; i < len; i = j){                     //starts outer loop from where inner loop ends
        ctr = 1;
        for(j = i+1; j < len; j++){
            if(s[i] == s[j])
                ctr++;
            else
                break;        
        }

        if(ctr > res)
            res = ctr;
    }

    return res;
}

int main()
{
    string s;
    cin>>s;

    cout<<max_rep(s);
    return 0;
}