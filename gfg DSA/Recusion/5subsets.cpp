//Generating all subsequences/SUBSETs of a str.         [len n  -->  #subsets = 2^n]
//T.C. theta(2^n)
//S.C. 

#include<iostream>
using namespace std;

void calc_subset(string &input, string curr = "", int i = 0) {
    if(i == input.length()) {
        cout<<curr <<endl;
        return;
    }

    calc_subset(input, curr, i+1);
    calc_subset(input, curr + input[i], i+1);
}

int main()
{
    string input;
    cout<<"\nEnter a string : ";
    cin>>input;
    int n = input.length();
    cout<<"\nFollowing are the subsets of the str. : \n";
    calc_subset(input);
    return 0;
}