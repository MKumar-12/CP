// Valid Parenthesis
//T.C. 
//S.C. 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        stack<char> temp;

        int i = 0;
        while(s[i] != '\0'){
            cout<<"\nChar read       : "<<s[i];
            
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);

            //keep a chk for emptiness of stk, i.e., if true, stk.top() returns Undefined behaviour.
            else if(s[i] == ')' && !st.empty() &&st.top() == '(')
                st.pop();
            else if(s[i] == '}' && !st.empty() && st.top() == '{')
                st.pop();
            else if(s[i] == ']' && !st.empty() && st.top() == '[')
                st.pop();
            else
                st.push(s[i]);
            
            
            cout<<"\nFinal stk is    : ";
            if(st.size() == 0) 
                cout<<"Empty";
            else {
                //we cannot iterate over the stk, so make a temp stack
                temp = st;

                while(!temp.empty()){
                    cout<<temp.top()<<" ";
                    temp.pop();
                }
            }
            cout<<endl;

            i++; 
        }      

        return st.empty();
    }
};


int main()
{
    Solution res;
    string s;
    cout<<"\nEnter a string consisting any of (){}[] : ";
    cin>>s;
    if(res.isValid(s))
        cout<<"\n\nStr. is balanced";
    else
        cout<<"\n\nNOT balanced";

    return 0;
}



//-------------Just balances the count, not ORDER---------------------------
        //bool isValid(string s) {
        //  vector<int> ctr (3,0);
        //  int i = 0;
        //  while(s[i] != '\0'){
        //      if(s[i] == '(')
        //          ctr[0]++;
        //      else if(s[i] == '{') 
        //          ctr[1]++;
        //      else if(s[i] == '[')
        //          ctr[2]++;
        //      else if(s[i] == ')')
        //          ctr[0]--;
        //      else if(s[i] == '}') 
        //          ctr[1]--;
        //      else if(s[i] == ']')
        //          ctr[2]--;

        //      i++;
        // }

        // if(ctr[0] == 0 && ctr[1] == 0 && ctr[2] == 0)
        //     return true;            //balanced
        
        // return false;
//---------------------------------------------------------------------------