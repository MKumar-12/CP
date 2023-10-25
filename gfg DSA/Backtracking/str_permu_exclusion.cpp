//Given a str., 
//  find all permutations of the str. that do not contain subs as the sub-str.
//T.C. 
//S.C. 

#include<iostream>
#include<string>
using namespace std;

void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permute(string str, int l, int r, string subs) {
    if(l == r) {
        // str.find() returns the index of 1st occurence of subs in str.
        //  if not present, it returns a special const. value 'string::npos' ~ not found
        //  {Search opr. didnt find the target sub-str.} 
        if(str.find(subs) == string::npos) {
            cout<<str<<endl;
        }
    }

    else {
        for(int i = l; i <= r; i++) {
            swap(&str[l], &str[i]);
            permute(str, l+1, r, subs);
            swap(&str[l], &str[i]);             //Back-tracking
        }
    }
}

int main()
{
    string s,subs;
    cout<<"\nEnter a String : ";
    cin>>s;

    cout<<"\nEnter the substr. to exclude : ";
    cin>>subs;

    cout<<"\nFollowing the permutations of the str. that do not contain "<<subs<<" as substring : "<<endl;
    permute(s, 0, s.length() - 1, subs);
    return 0;
}