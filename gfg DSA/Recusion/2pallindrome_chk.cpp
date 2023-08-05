//Pallindrome chk using Recursion
//if str == rev(str)
//T.C. theta(n)
//S.C. theta(n)

#include<iostream>
#include<string.h>
using namespace std;

//str is passed by ref. to avoid copy operation
bool pallindrome_chk(string &input, int start, int end) {
    if(start >= end)
        return true;

    return (input[start] == input[end]) && pallindrome_chk(input, start+1, end-1);
}

int main()
{
    string input;
    cout<<"\nEnter a string : ";
    cin>>input;
    int n = input.length();
    //cout<<"\nStr. len : "<<n;
    if(pallindrome_chk(input,0,n-1))
        cout<<"\nGiven string is Pallindrome!!";
    else    
        cout<<"\nNot Pallindrome!!";
    return 0;
}