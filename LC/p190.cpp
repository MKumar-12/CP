//Reverse Bits
//T.C. 
//S.C. 

#include<bits/stdc++.h>
using namespace std;

// string rev_str(string s, int start, int end){
//     if(s.length() <= 1)
//         return s;
    
//     while(start <= end){
//         char temp = s[start];
//         s[start] = s[end];
//         s[end] = temp;
//         start++;
//         end--;
//     }

//     return s;
// }

// int calc_rev(string s) {
//     int len = s.length();
//     string rev = rev_str(s, 0 , len-1);
    
//     cout<<"\nReversed str. is as follows : "<<rev;

//     cout<<"\nLength rev : "<<rev.length();

//     int res = 0;
//     int max_posi = rev.length() - 1;
//     for(int i = 0; i<= rev.length() - 1 ; i++) {
//         res +=  pow(2,max_posi) * rev[i];
//         max_posi--;
//         cout<<"\n"<<res;
//     }

//     return res;
// }

int calc_val(string s) {
    int sum = 0, curr_pow = 0;
    for(int i = 0; i<s.length(); i++){
        if(s[i] == '1')
            sum += pow(2,curr_pow);
        
        // cout<<sum<<endl;
        curr_pow++;
        
    }
    return sum;
}

int main()
{
    string s;
    cout<<"\nEnter a 32-bit no. : ";    //  11111111111111111111111111111101
    cin>>s;

    //cout<<"\n\nDecimal value of its rev : "<<calc_rev(s);

    cout<<"\n\nDecimal value of its rev : "<<calc_val(s);

    return 0;
}