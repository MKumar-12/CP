// Single Ouccuring element

/*
    All elements repeated twice except for 1
    Return the single element
*/
//T.C. 
//S.C. 

#include<bits/stdc++.h>
using namespace std;

// ------------------------Approach 1---------------------------
// Using HashMap to store count of each var.
//
// T.C O(n)
// S.C O(n)
int calc_single1(vector<int> n) {                       
    map<int,int> hash;
    
    //filling entries
    for(auto i : n){    
        if(hash[i] == 0)
            hash[i] = 1;
        else 
            hash[i]++;
    }

    cout<<"\n\nHashmap is as follows : "<<endl;
    for(auto it: hash) {
        cout<<it.first<<" : "<<it.second<<endl;
    }

    //finding the single element
    for(auto it : hash){
        if(it.second == 1)
            return it.first;
    }
}
// -------------------------------------------------------------



// ------------------------Approach 2---------------------------
// Using Set to store distinct values
// 2xsum(set_val) - sum(org_input) =    Missing single element
//
// T.C O(n)
// S.C O(n)
int calc_single2(vector<int> n) {                       
    set<int> s;
    int org_sum = 0, set_sum = 0;

    for(auto it : n) {
        org_sum += it;
        s.insert(it);
    }

    for(auto itr : s){
        set_sum += itr;
    }

    cout<<"\nSet sum : "<<set_sum;
    cout<<"\nOrg sum : "<<org_sum;
    
    return (2*set_sum - org_sum);
}
// -------------------------------------------------------------



// ------------------------Approach 3---------------------------
// Sort the elements 1st
// chk ith and (i+1)th val in arr,     if not same -->  Missing single element
// inc. i by 2
//
// T.C O(n logn)
// S.C O(1)
int calc_single3(vector<int> n) {                       
    sort(n.begin(), n.end());

    cout<<"\nAfter Sort          : ";
    for(auto i: n) {
        cout<<i<<" ";
    }

    for(int i = 0; i <= n.size(); i = i+2){
        if(n[i] != n[i+1])
            return n[i];
    }
}
// -------------------------------------------------------------



// ------------------------Approach 4---------------------------
// Count occurence of each element in the list
// whichever element is present only once   --> return   
//
// T.C O(n^2)
// S.C O(1)
int calc_single4(vector<int> n) {
    for (int i = 0; i < n.size(); i++)
    {
        int ctr = 0;
        for(int j = 0; j < n.size(); j++)
        {
            if(n[i] == n[j])
                ctr++;
        } 
        if(ctr%2 != 0) 
            return n[i]; 
    }
}
// -------------------------------------------------------------



// ------------------------Approach 5---------------------------
// Perform XOR opr. on all elements of list
// x XOR x = 0      --> scraps off elements which are present twice
// 0 XOR x = x      --> it'll help identify solo element  
//
// T.C O(n)
// S.C O(1)
int calc_single5(vector<int> n) {
    int res = n[0];

    //0-indexed vector                       
    for(int i= 1; i < n.size(); i++) {
        res = res ^ n[i];
    }

    return res;
}
// -------------------------------------------------------------



int main()
{
    vector<int> n;
    cout<<"\nEnter the no.(s)    : ";   //  2 4 4 5 1 5 2
    int temp; 
    while(true) {
        cin>>temp;
        if(cin.peek() == '\n'){
            n.push_back(temp);
            break;
        }
        else
            n.push_back(temp);
    }

    // cout<<"\nInput is as follows : ";
    // for(auto it : n) {
    //     cout<<it<<" ";
    // }

    // cout<<"\n\nSingle element in list is : "<<calc_single1(n);       // Approach 1
    // cout<<"\n\nSingle element in list is : "<<calc_single2(n);       // Approach 2
    // cout<<"\n\nSingle element in list is : "<<calc_single3(n);       // Approach 3
    // cout<<"\n\nSingle element in list is : "<<calc_single4(n);       // Approach 4
    cout<<"\n\nSingle element in list is : "<<calc_single5(n);       // Approach 5  - optimal
    

    return 0;
}