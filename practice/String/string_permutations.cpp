//Given a str., 
//  find all permutations of the str.

//T.C. 
//S.C. 

#include<iostream>
#include<string>
using namespace std;
int ctr = 0;

void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp; 
}

void permute(string str, int l, int r) {
    //base-case
    //all possible exchanges made for i'th and l'th position char. swaps
    if(l == r) {
        ctr++;
        cout<<str<<endl;
    }

    else {
        for(int i = l; i <= r; i++) {
            swap(&str[l], &str[i]);
            permute(str, l+1, r);
            swap(&str[l], &str[i]);             //Back-tracking
            //to bring bach the neutral/org. state of str.
            //  {REQD. cause we had made swaps in the org. string, inorder to save space}
        }
    }
}

int main()
{
    string s;
    cout<<"\nEnter a String : ";
    cin>>s;

    cout<<"\nFollowing the permutations of the str. : "<<endl;
    permute(s, 0, s.length() - 1);

    cout<<"\n\n#Permutations : "<<ctr;      //  n! 
    return 0;
}