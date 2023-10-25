//Huffman Coding

/*
    Used for lossless compression
    Var. len. encoding of 'char' repeated over multiple times.
    Converts the data/str. into     -->         bit-stream
    Prefix-FREE codes               {achieved using B-tree}

    Greedy idea :
        Most frequent bit has the smallest code

        Codes have unique prefix    { for easy decompression }

    
*/

//T.C. 
//S.C. 

#include<bits/stdc++.h>
using namespace std;


// custom comparator for sorting.
bool mycomp(pair<char,int> &a , pair<char,int> &b) {
    return a.second > b.second;
}

int main()
{
    int n;
    cout<<"\nEnter the no. of distinct char. in msg : ";         //  3       6
    cin>>n;

    char var;
    int freq;
    vector<pair<char,int>> char_freq;
    cout<<"\nEnter the char. and its freq. count : "<<endl;
    for(int i =0; i<n; i++){
        cin>>var>>freq;
        //  a 70 b 20 c 10
        //  a 28 b 14 c 20 d 4 e 12 f 22
        char_freq.push_back(make_pair(var,freq));
    }

    sort(char_freq.begin(), char_freq.end(), mycomp);
    cout<<"\nFollowing are the char along with their count in DESCREASING order sorted : "<<endl;
    for(auto i: char_freq) {
        cout<<i.first<<" : "<<i.second<<endl;
    }

    return 0;
}